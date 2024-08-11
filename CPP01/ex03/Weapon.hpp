#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string _type);
		void		setType(std::string weapon);
		std::string	const &getType(void);
};

#endif
