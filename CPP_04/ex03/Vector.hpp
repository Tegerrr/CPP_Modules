#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "AMateria.hpp"

class Vector
{
	private:
		AMateria **storage;
		int capacity; // new_capacity = capacity * 2 + 1
		int used;

	public:
		Vector();
		~Vector();
		void add(AMateria *m);
};

#endif