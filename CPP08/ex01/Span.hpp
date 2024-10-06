#ifndef Span_hpp
#define Span_hpp

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _array;

	public:
		Span();
		Span(unsigned int _size);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber(int n);
		void addLots(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#endif