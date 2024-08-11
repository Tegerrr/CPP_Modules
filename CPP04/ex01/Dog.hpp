#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &Copy);
		Dog	&operator=(Dog const &other);

		void		makeSound(void) const;
		std::string	GetType(void) const;
		Brain		*GetBrain(void) const;
};

#endif