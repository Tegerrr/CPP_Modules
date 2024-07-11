#include "FragTrap.hpp"

int main()
{
	ClapTrap	cguy("Clap Guy");
	ScavTrap	sguy("Scav Guy");
	FragTrap	tguy("Frag Guy");

	std::cout << std::endl;
	cguy.attack("Bear");
	cguy.takeDamage(5);
	cguy.beRepaired(20);
	cguy.takeDamage(30);
	cguy.beRepaired(100);
	cguy.attack("Bear");
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

	tguy.attack("Bear");
	tguy.takeDamage(5);
	tguy.beRepaired(20);
	tguy.takeDamage(30);
	tguy.beRepaired(100);
	tguy.attack("Bear");
	tguy.takeDamage(200);
	tguy.beRepaired(100);
	tguy.attack("Bear");
	std::cout << std::endl;
	tguy.highFivesGuys();
	std::cout << std::endl;
	return 0;
}