#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string const &_name);
		ScavTrap(ScavTrap const &copy);
		~ScavTrap();
		
		ScavTrap	&operator=(ScavTrap const &other);
		void		setName(std::string	name);

		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		void		guardGate();

};

#endif