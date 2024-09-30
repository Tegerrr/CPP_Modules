#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./converter <input>" << std::endl;
		return 1;
	}
	ScalarConverter input;
	try
	{
		input.convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}