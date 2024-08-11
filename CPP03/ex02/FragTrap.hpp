#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(std::string const &_name);
		FragTrap(FragTrap const &copy);
		~FragTrap();
		
		FragTrap	&operator=(FragTrap const &other);
		void		setName(std::string	name);
		void		highFivesGuys(void);
};

#endif