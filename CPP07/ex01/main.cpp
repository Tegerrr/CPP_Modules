#include "Iter.hpp"
#include <string>

int main(void)
{

	std::cout << "__________________\n" << std::endl;

	std::string str[3] = {
		"lala",
		"bebe",
		"zuzu"
	};
	iter(str, 3, print);

	std::cout << "__________________\n" << std::endl;

	return (0);
}