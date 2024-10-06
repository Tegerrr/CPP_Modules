#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::~Span() {}

Span::Span(const Span &other) : _size(0)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_array = other._array;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_array.size() == _size)
		throw std::out_of_range("Array is full");
	_array.push_back(n);
}

void Span::addLots(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_array.size() + std::distance(begin, end) > _size)
		throw std::out_of_range("Array is full");
	_array.insert(_array.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_array.size() < 2)
		throw std::out_of_range("Array is too small");
	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());
	int min = INT_MAX;
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

int Span::longestSpan()
{
	if (_array.size() < 2)
		throw std::out_of_range("Array is too small");
	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

