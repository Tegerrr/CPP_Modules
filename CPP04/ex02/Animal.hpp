#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(std::string otherType);
		virtual ~Animal(void);
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &other);
		
		virtual	void				makeSound(void) const = 0;
		virtual std::string			getType(void) const;
		virtual Brain				*GetBrain(void) const;
};

#endif