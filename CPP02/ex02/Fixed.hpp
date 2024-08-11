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

		Fixed			&operator=(const Fixed &copy);
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;
		Fixed	   		operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed	   		operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;
		Fixed	   		&operator++(void);
		Fixed			operator++(int);
		Fixed   		&operator--(void);
		Fixed			operator--(int);
		static Fixed   		&max(Fixed &a, Fixed &b);
		static Fixed			&min(Fixed &a, Fixed &b);
		static const Fixed		&max(const Fixed &a, const Fixed &b);
		static const Fixed		&min(const Fixed &a, const Fixed &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
        int		toInt(void) const;
};

#endif