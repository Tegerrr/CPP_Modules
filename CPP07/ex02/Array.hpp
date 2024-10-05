#ifndef Array_hpp
# define Array_hpp

# include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		unsigned int size() const;
		class OutOfBoundsException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

# include "Array.tpp"

#endif