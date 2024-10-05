#ifndef ScalarConverter_hpp
# define ScalarConverter_hpp

# include <iostream>
# include <string>
# include <exception>
# include <iomanip>
# include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

	public:
		static void convert(std::string input);
};

#endif