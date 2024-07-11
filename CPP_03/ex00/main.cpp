#include "ClapTrap.hpp"

int main()
{
	ClapTrap	fguy("First Guy");
	ClapTrap	sguy(fguy);
	ClapTrap	tguy;

	tguy = sguy;
	std::cout << std::endl;

	sguy.setName("Second Guy");
	tguy.setName("Third Guy");

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
	std::cout << std::endl;

	tguy.attack("Bear");
	tguy.takeDamage(5);
	tguy.beRepaired(20);
	tguy.takeDamage(30);
	tguy.beRepaired(100);
	tguy.attack("Bear");
	std::cout << std::endl;
	return 0;
}