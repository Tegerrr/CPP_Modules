#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs) {
	}
	return *this;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

void inplaceMerge(std::list<int>::iterator first, 
                   std::list<int>::iterator middle, 
                   std::list<int>::iterator last) 
{
    std::list<int> temp;
    std::list<int>::iterator left = first;
    std::list<int>::iterator right = middle;

    while (left != middle && right != last) {
        if (*left <= *right) {
            temp.push_back(*left);
            ++left;
        } else {
            temp.push_back(*right);
            ++right;
        }
    }

    while (left != middle) {
        temp.push_back(*left);
        ++left;
    }

    while (right != last) {
        temp.push_back(*right);
        ++right;
    }

    std::list<int>::iterator it = first;
    for (std::list<int>::iterator temp_it = temp.begin(); temp_it != temp.end(); ++temp_it) {
        *it = *temp_it;
        ++it;
    }
}


void PmergeMe::fordJohnsonAlgorithmVector(int begin, int end)
{
    if (end - begin <= 1)
        return;

    int middle = (begin + end) / 2;

    fordJohnsonAlgorithmVector(begin, middle);
    fordJohnsonAlgorithmVector(middle, end);

    std::inplace_merge(_vec.begin() + begin, _vec.begin() + middle, _vec.begin() + end);
}

void PmergeMe::fordJohnsonAlgorithmList(std::list<int>::iterator begin, std::list<int>::iterator end) 
{
    if (std::distance(begin, end) <= 1)
        return;

    std::list<int>::iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);

    fordJohnsonAlgorithmList(begin, middle);
    fordJohnsonAlgorithmList(middle, end);

    inplaceMerge(begin, middle, end);
}

void PmergeMe::printVector(const std::vector<int>& vector)
{
	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printList(const std::list<int>& list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::sortVec()
{
	clock_t start = clock();
	std::cout << "Before: ";
	printVector(_vec);
	fordJohnsonAlgorithmVector(0, _vec.size());
	clock_t end = clock();
	std::cout << "After: ";
	printVector(_vec);
	std::cout << "Time to process a range of "
		<< _vec.size()
			<< " with std::vector : "
				<< static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0 << " us" << std::endl;
}

void PmergeMe::sortList()
{
	clock_t start = clock();
	std::cout << "Before: ";
	printList(_list);
	fordJohnsonAlgorithmList(_list.begin(), _list.end());
	clock_t end = clock();
	std::cout << "After: ";
	printList(_list);
	std::cout << "Time to process a range of "
		<< _list.size()
			<< " with std::list : "
				<< static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0 << " us" << std::endl;
}


void PmergeMe::checkIfValid(int argc, char **argv)
{
	if (argc < 2)
		throw InvalidInputException();
	for (int i = 1; argv[i]; i++)
	{
		if (std::atol(argv[i]) > INT_MAX || std::atol(argv[i]) < 0 || !argv[i][0])
			throw InvalidInputException();
		for (int j = 0; argv[i][j]; j++)
		{
			if (!std::isdigit(argv[i][j]) || argv[i][j] < '0' || argv[i][j] > '9')
				throw InvalidInputException();
		}
        _vec.push_back(std::atoi(argv[i]));
        _list.push_back(std::atoi(argv[i]));
	}
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	checkIfValid(argc, argv);
}
