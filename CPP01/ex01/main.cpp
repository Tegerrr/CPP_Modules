#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int main()
{
	int	N;

	std::cout << "Enter the amount of Zombies: ";
	std::cin >> N;
	if (N > 0 && N < INT_MAX)
	{
		Zombie *Horde = zombieHorde(N, "Zombie");
		for (int i = 0; i < N; i++)
			Horde[i].announce();
		delete[] Horde;
	}
	else
	{
		std::cout << "Invalid Zzzombie amount!" << std::endl;
		return 1;
	}
	return 0;
}
