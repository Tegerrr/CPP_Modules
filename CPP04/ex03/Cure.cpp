#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(std::string const type)
{
	_type = type;
}

Cure::~Cure() {}

Cure::Cure(Cure const &copy)
{
	*this = copy;
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria	*Cure::clone(void) const
{
	return new Cure(_type);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
