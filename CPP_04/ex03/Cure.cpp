#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure default destructor called" << std::endl;
}

Cure::Cure(Cure const &copy)
{
	*this = copy;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria	*Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
