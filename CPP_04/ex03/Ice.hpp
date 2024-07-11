#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice(void);
		Ice(std::string const type);
		~Ice(void);
		Ice(Ice const &copy);
		Ice	&operator=(Ice const &other);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif