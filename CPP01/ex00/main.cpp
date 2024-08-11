#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	StackZombie("Stack Zombie");
	StackZombie.announce();

	Zombie	*HeapZombie = newZombie("Heap Zombie");
	HeapZombie->announce();

	randomChump("Random Zombie");
	delete HeapZombie;

	return 0;
}
