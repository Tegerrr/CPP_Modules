#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _n(n) {}

template <typename T>
Array<T>::Array(const Array &other)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	if (_array)
		delete[] _array;
	_n = other._n;
	_array = new T[_n];
	for (unsigned int i = 0; i < _n; i++)
		_array[i] = other._array[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _n)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _n;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Out of bounds";
}
