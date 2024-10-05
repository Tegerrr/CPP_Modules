#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <string>
#include <stdint.h>

class Serializer
{
	private:
		Serializer();

	public:
		typedef struct Data
		{
			int i;
		} Data;

		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif