#include "Vector.hpp"

Vector::Vector() : storage(NULL), capacity(0), used(0) {}

void Vector::add(AMateria *m)
{
	if (used == capacity) 
	{
		int new_capacity = capacity * 2 + 1;
		AMateria **new_storage = new AMateria *[new_capacity];
		for (int i = 0; i < capacity; i++)
			new_storage[i] = storage[i];
		delete[] storage;
		storage = new_storage;
		capacity = new_capacity;
	}
	storage[used] = m;
}

Vector::~Vector()
{
	for (int i = 0; i < used; i++)
		delete storage[i];
	delete [] storage;
}
