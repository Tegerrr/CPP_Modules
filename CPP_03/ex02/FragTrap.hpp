#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
	public:

		FragTrap(void);
		FragTrap(std::string const &_name);
		FragTrap(FragTrap const &copy);
		~FragTrap();
		
		FragTrap	&operator=(FragTrap const &other);
		void		setName(std::string	name);

		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		void		highFivesGuys(void);
};

#endif