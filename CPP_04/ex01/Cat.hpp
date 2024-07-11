#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &Copy);
		Cat	&operator=(Cat const &other);

		void		makeSound(void) const;
		std::string	GetType(void) const;
		Brain		*GetBrain(void) const;
};

#endif