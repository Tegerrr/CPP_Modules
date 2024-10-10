#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	try
	{
		PmergeMe pmm(argc, argv);
		pmm.sortVec();
		pmm.sortList();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}