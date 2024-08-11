#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_name = "Scav";
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "(frag) Default constructor created a Normie" << std::endl;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	_name = name;
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "(frag) Constructor created a " << _name << std::endl;
}


FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "(frag) Copy constructor copied " << _name << std::endl;
	*this = copy;
}

FragTrap::~FragTrap(void)
{
	std::cout << "(frag) Default destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	std::cout << "(frag) Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_damage = other._damage;
		_health = other._health;
		_energy = other._energy;
	}
	return *this;
}

void	FragTrap::setName(std::string name)
{
	_name = name;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "(frag) " << _name << " gives a high five!!!" << std::endl;
}
