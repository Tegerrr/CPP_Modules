#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	protected:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character(void);
		Character(std::string name);
		~Character(void);
		Character(Character const &copy);
		Character	&operator=(Character const &other);

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		std::string const &getName(void) const;
};

#endif