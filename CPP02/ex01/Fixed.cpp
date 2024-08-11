#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_fixval = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_val)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixval = i_val << bits;
}

Fixed::Fixed(const float f_val)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixval = roundf(f_val * (1 << bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_fixval = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixval;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixval = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_fixval / (1 << bits);
}

int Fixed::toInt(void) const
{
    return this->_fixval >> bits;
}
