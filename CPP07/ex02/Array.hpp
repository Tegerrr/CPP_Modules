#ifndef Array_hpp
# define Array_hpp

class Array
{
	private:
		Array();
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);

	public:
		static void *array;
};

#endif
