#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <algorithm>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::list<int> _list;

public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& rhs);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& rhs);

	void fordJohnsonAlgorithmVector(int begin, int end);
	void fordJohnsonAlgorithmList(std::list<int>::iterator begin, std::list<int>::iterator end);
	void checkIfValid(int argc, char **argv);
	void sortVec();
	void sortList();
	void printVector(const std::vector<int>& container);
	void printList(const std::list<int>& list);
	

	class InvalidInputException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
