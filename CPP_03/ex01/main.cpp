#include "ScavTrap.hpp"

int main()
{
	ClapTrap	fguy("Clap Guy");
	ScavTrap	sguy("Scav Guy");

	std::cout << std::endl;

	fguy.attack("Bear");
	fguy.takeDamage(5);
	fguy.beRepaired(20);
	fguy.takeDamage(30);
	fguy.beRepaired(100);
	fguy.attack("Bear");
	std::cout << std::endl;

	sguy.attack("Bear");
	sguy.takeDamage(5);
	sguy.beRepaired(20);
	sguy.takeDamage(30);
	sguy.beRepaired(100);
	sguy.attack("Bear");
	sguy.takeDamage(200);
	sguy.beRepaired(100);
	sguy.attack("Bear");
	std::cout << std::endl;
	sguy.guardGate();
	std::cout << std::endl;

	return 0;
}