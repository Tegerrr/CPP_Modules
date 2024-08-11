#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria(){}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	_type = other._type;
	return *this;
}

std::string const &AMateria::getType(void) const
{
	return _type;
}

void AMateria::use(ICharacter&){}
