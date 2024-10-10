#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib> // For std::atof
#include <iomanip> // For std::fixed, std::setprecision

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& rhs);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& rhs);

    void loadDatabase(const std::string& filename);
    void processTransactions(const std::string& filename);

    class FileReadException : public std::exception {
        const char* what() const throw();
    };

private:
    std::map<std::string, float> database;

    bool validateDate(const std::string& date) const;
    bool validateValue(const std::string& value) const;
    void printError(const std::string& msg, const std::string& line) const;
    float getRateForDate(const std::string& date) const;
    bool validateValueGenerate(const std::string& value) const;
};

#endif