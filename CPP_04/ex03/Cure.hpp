#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		~Cure();
		Cure(Cure const &copy);
		Cure &operator=(Cure const &other);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif