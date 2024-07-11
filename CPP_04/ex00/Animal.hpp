#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(std::string otherType);
		~Animal(void);
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &other);

		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif