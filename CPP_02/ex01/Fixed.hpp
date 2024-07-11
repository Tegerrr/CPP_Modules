#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <string>
# include <iostream>

class Fixed
{
	private:
		int					_fixval;
		static const int	bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int	val);
		Fixed(const float val);
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
        int		toInt(void) const;
};

#endif