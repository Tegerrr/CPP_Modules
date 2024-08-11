#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	_name = "Scav";
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "(scav) Default constructor created a Normie" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	_name = name;
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "(scav) Constructor created a " << _name << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "(scav) Copy constructor copied " << _name << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "(scav) Default destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "(scav) Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_damage = other._damage;
		_health = other._health;
		_energy = other._energy;
	}
	return *this;
}

void	ScavTrap::setName(std::string name)
{
	_name = name;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_health > 0 && _energy)
	{
		std::cout << "(scav) " << _name << " tries to fight back from a " << target << " Dealing " << _damage << " damage!" << std::endl;
		_energy--;
	}
	else
		std::cout << "(scav) " << _name << " is freaking dead man! He can't even attack, call an ambulance!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "(scav) " << _name << " is now in Gate Keeper mode!" << std::endl;
}


