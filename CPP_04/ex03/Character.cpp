#include "Character.hpp"
#include "Vector.hpp"

static Vector global_vector;

Character::Character()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name)
{
	_name = name;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	std::cout << "Character default destructor called" << std::endl;
}

Character::Character(Character const &copy)
{
	*this = copy;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
			if (copy._inventory[i] != NULL)
				_inventory[i] = copy._inventory[i];
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(Character const &other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	global_vector.add(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
		_inventory[idx]->use(target);
	else if (idx < 0 || idx > 3)
		std::cout << "Index " << idx << "doesn't exist!" << std::endl;
	else if (_inventory[idx] == NULL)
		std::cout << "Invrntory slot " << idx << " is empty!" << std::endl;
}
std::string const &Character::getName(void) const
{
	return _name;
}
