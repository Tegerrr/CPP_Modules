#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name)
		{
			_name = name;
		}
		~Zombie(void);
		void	announce(void);
};

#endif