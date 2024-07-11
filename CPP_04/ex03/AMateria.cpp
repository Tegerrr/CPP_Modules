#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::~AMateria()
{

}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(AMateria const &)
{

	return *this;
}

std::string const &AMateria::getType(void) const
{
	return _type;
}

void AMateria::use(ICharacter&){}
