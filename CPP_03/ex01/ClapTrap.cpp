#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):	_name("Normie"),
							_health(10),
							_energy(10),
							_damage(0)
{
	std::cout << "Default constructor created a Normie" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name):	_name(name),
												_health(10),
												_energy(10),
												_damage(0)
{
	std::cout << "Constructor created a " << _name << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "Copy constructor copied " << _name << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_damage = other._damage;
		_health = other._health;
		_energy = other._energy;
	}
	return *this;
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_health > 0 && _energy)
	{
		std::cout << _name << " tries to fight back from a " << target << " Dealing " << _damage << " damage!" << std::endl;
		_energy--;
	}
	else
		std::cout << _name << " is freaking dead man! He can't even attack, call an ambulance!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_health)
	{
		std::cout << "Bear keeps on attacking " << _name << " but " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (amount > _health)
		_health = amount;
	_health -= amount;
		std::cout << "Oh no! " << _name << " is being mauled! Taking " << amount << " damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_health)
	{
		std::cout << _name << " can't even heal bro, he's dead!" << std::endl;
		return ;
	}
	if (_energy)
	{
		if ((_health + amount) < _health)
			_health = UINT_MAX;
		else
			_health += amount;
		_energy--;
		std::cout << _name << " manages to heal himself for " << amount << " health points!" << std::endl;
	}
	else
		std::cout << _name << " is exhausted! He can't even heal, he has no energy!" << std::endl;
}
