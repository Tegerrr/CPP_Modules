#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain	&operator=(const Brain &other);		
		
		std::string	*GetIdeas(void);
};

#endif
