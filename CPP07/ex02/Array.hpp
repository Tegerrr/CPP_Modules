#ifndef Array_hpp
# define Array_hpp

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array &other) : _array(NULL), _size(0) { *this = other; }
		~Array() { delete [] _array; }

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Index out of bounds"; }
		};

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete [] _array;
				_array = new T[other._size];
				for (unsigned int i = 0; i < other._size; i++)
					_array[i] = other._array[i];
				_size = other._size;
			}
			return *this;
		}

		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw OutOfBounds();
			return _array[i];
		}
};

#endif
