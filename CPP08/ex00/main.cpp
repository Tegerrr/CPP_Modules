#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try
	{
		std::cout << easyFind(vec, 5) << std::endl;
		std::cout << easyFind(vec, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
