#include "Iter.hpp"
#include <string>

int main(void)
{
	std::string str[3] = {
		"lala",
		"bebe",
		"zuzu"
	};
	iter(str, 3, print);

	return (0);
}