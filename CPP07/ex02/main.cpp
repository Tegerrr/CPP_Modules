#include "Array.hpp"

int main()
{
	Array<int> arr(5);
	Array<char> arr2(2);

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		arr[i] = i;
		std::cout << arr[i] << std::endl;
	}
	std::cout << "__________________\n" << std::endl;

	for (unsigned int i = 0; i < arr2.size(); i++)
	{
		arr2[i] = i + 65;
		std::cout << arr2[i] << std::endl;
	}
	try
	{
		arr[5] = 10;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}