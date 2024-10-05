#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        return *this;
    return *this;
}

bool checkIfScience(std::string input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return true;
	}
	return false;
}


void printInfo(char c, int i, float f, double d)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::fixed << std::setprecision(1) << std::endl;
}

void convertChar(std::string input)
{
	char c = input[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printInfo(c, i, f, d);
}

bool convertDigit(std::string input)
{
	double num;

	try { num = std::stoi(input); }
	catch (const std::out_of_range& e) {
        std::cerr << "Error: Number is out of range: " << e.what() << std::endl;
        return false; }
	char c = static_cast<char>(num);
	int i = static_cast<int>(num);
	float f = static_cast<float>(num);
	double d = static_cast<double>(num);
	printInfo(c, i, f, d);
	return true;
}


bool checkType(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
	{
		convertChar(input);
		return true;
	}
	else if (isdigit(input[0]) || input[0] == '-' || input[0] == '+')
	{
		bool dot = false;
		for (size_t i = 0; i < input.length(); i++)
		{
			if ((input[i] == '+' || input[i] == '-') && i == 0)
				continue;
			if (!isdigit(input[i]))
			{
				if (input[i] == '.')
				{
					if (dot == true)
						return false;
					dot = true;
					continue;
				}
				if (i == input.length() - 1 && input[i] == 'f')
					break;
				throw false;
			}
		}
		if (convertDigit(input) == true)
			return true;
	}
	return false;
}


void ScalarConverter::convert(std::string input)
{
	if (input.empty())
		std::cerr << "Invalid Input" << std::endl;
	if (checkIfScience(input))
		return ;
	if (checkType(input) == false)
		std::cerr << "Invalid Input" << std::endl;
}
