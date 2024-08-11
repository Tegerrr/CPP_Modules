#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	private:

		std::string				_name;
		unsigned int			_health;
		unsigned int			_energy;
		unsigned int			_damage;

	public:

		ClapTrap(void);
		ClapTrap(std::string const &_name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap();
		
		ClapTrap	&operator=(ClapTrap const &other);
		void		setName(std::string	name);

		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

};

#endif