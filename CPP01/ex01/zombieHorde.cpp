#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie *Horde = new Zombie[n];
	for (int i = 0; i < n; i++)
		Horde[i].setName(name);
	return (Horde);
}
