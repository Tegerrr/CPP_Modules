#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_name = "Scav";
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "(frag) Default constructor created a Normie" << std::endl;
}

FragTrap::FragTrap(std::string const &name): ScavTrap(name)
{
	_name = name;
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "(frag) Constructor created a " << _name << std::endl;
}


FragTrap::FragTrap(FragTrap const &copy): ScavTrap(copy)
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

void	FragTrap::attack(const std::string& target)
{
	if (_health > 0 && _energy)
	{
		std::cout << "(frag) " << _name << " tries to fight back from a " << target << " Dealing " << _damage << " damage!" << std::endl;
		_energy--;
	}
	else
		std::cout << "(frag) " << _name << " is freaking dead man! He can't even attack, call an ambulance!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (!_health)
	{
		std::cout << "(frag) Bear keeps on attacking " << _name << " but " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (amount > _health)
		_health = amount;
	_health -= amount;
	std::cout << "(frag) Oh no! " << _name << " is being mauled! Taking " << amount << " damage!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (!_health)
	{
		std::cout << "(frag) " << _name << " can't even heal bro, he's dead!" << std::endl;
		return ;
	}
	if (_energy)
	{
		if ((_health + amount) < _health)
			_health = UINT_MAX;
		else
			_health += amount;
		_energy--;
		std::cout << "(frag) " << _name << " manages to heal himself for " << amount << " health points!" << std::endl;
	}
	else
		std::cout << "(frag) " << _name << " is exhausted! He can't even heal, he has no energy!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "(frag) " << _name << " gives a high five!!!" << std::endl;
}
