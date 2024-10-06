#include "Array.hpp"

int main()
{
	Array<int> arr(5);
	Array<int> arr2(5);
	Array<char> arr3(5);

	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
		std::cout << arr[i] << std::endl;
	}
	try
	{
		std::cout << arr[6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}