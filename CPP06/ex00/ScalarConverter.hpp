#ifndef ScalarConverter_hpp
# define ScalarConverter_hpp

# include <iostream>
# include <string>
# include <exception>
# include <iomanip>

class ScalarConverter
{
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

		static void convert(std::string input);
		static void checkType(std::string input);

		class InvalidException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif