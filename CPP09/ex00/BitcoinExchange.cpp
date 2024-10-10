#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
    *this = rhs;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs)
        this->database = rhs.database;
    return *this;
}

const char* BitcoinExchange::FileReadException::what() const throw() {
    return "Error reading the file.";
}

bool BitcoinExchange::validateDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 1000 || year > 9999 || month < 1 || month > 12)
        return false;

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    return day > 0 && day <= daysInMonth[month - 1];
}

bool BitcoinExchange::validateValue(const std::string& value) const {
    if (value.empty() || value[0] == '-')
        return false;

    bool decimalFound = false;
    for (std::string::const_iterator it = value.begin(); it != value.end(); ++it) {
        if (*it == '.') {
            if (decimalFound) return false;
            decimalFound = true;
        } else if (!std::isdigit(*it)) {
            return false;
        }
    }

    float floatValue = std::atof(value.c_str());
    return floatValue > 0 && floatValue <= 1000;
}

bool BitcoinExchange::validateValueGenerate(const std::string& value) const {
    if (value.empty() || value[0] == '-')
    {
        return false; 
    }
    bool decimalFound = false;
    for (std::string::const_iterator it = value.begin(); it != value.end(); ++it) {
        if (*it == '.') {
            if (decimalFound) return false;
            decimalFound = true;
        } else if (!std::isdigit(*it)) {
            return false;
        }
    }
    float floatValue = std::atof(value.c_str());
    if (floatValue == 0)
        return true;
    return floatValue;
}

void BitcoinExchange::printError(const std::string& msg, const std::string& line) const {
    std::cout << "Error: " << msg << " => " << line << std::endl;
}

float BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);
    if (it == database.end() || (it != database.begin() && date != it->first))
        --it;

    if (it == database.end()) {
        printError("no exchange rate available", date);
        return 0.0f;
    }
	// std::cout << "\ndate: " << it->first << " rate: " << it->second << std::endl;
    return it->second;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file;
	file.open(filename.c_str());
    if (!file.is_open())
        throw FileReadException();
    std::string line;
    while (std::getline(file, line)) {
        if (line == "date,exchange_rate")
            continue;
        std::size_t delimPos = line.find(',');
        if (delimPos == std::string::npos)
            continue;
            // std::cout << "line: " << line << std::endl;

        std::string date = line.substr(0, delimPos);
        // std::cout << "date: " << date << std::endl;
        std::string value = line.substr(delimPos + 1);

        if (!validateDate(date) || !validateValueGenerate(value))
            continue;

        database[date] = std::atof(value.c_str());
    }

    file.close();
}

void BitcoinExchange::processTransactions(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileReadException();

    std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw FileReadException();
    while (std::getline(file, line)) {
        // if (line == "date | value")
        //     continue;

        std::size_t delimPos = line.find('|');
        if (delimPos == std::string::npos) {
            printError("bad input", line);
            continue;
        }

        std::string date = line.substr(0, delimPos - 1);
        std::string value = line.substr(delimPos + 2);
        if (!validateDate(date)) {
            printError("bad input", date);
            continue;
        }
        if (!validateValue(value)) {
            if (std::atof(value.c_str()) <= 0) {
                printError("not a positive number", value);
            } else {
                printError("too large a number", value);
            }
            continue;
        }

        float floatValue = std::atof(value.c_str());
        float exchangeRate = getRateForDate(date);
        
            std::cout << date << " => " << value << " = " 
                      << exchangeRate * floatValue << std::endl;
    }

    file.close();
}