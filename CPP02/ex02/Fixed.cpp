#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_fixval = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_val)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixval = i_val << bits;
}

Fixed::Fixed(const float f_val)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixval = roundf(f_val * (1 << bits));
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    (*this) = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_fixval = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
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

bool    Fixed::operator>(const Fixed &other) const
{
    return _fixval > other._fixval;
}

bool    Fixed::operator<(const Fixed &other) const
{
    return _fixval < other._fixval;
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return _fixval <= other._fixval;
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return _fixval >= other._fixval;
}

bool    Fixed::operator==(const Fixed &other) const
{
    return _fixval == other._fixval;
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return _fixval != other._fixval;
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    Fixed   temp(*this);
    temp._fixval += other.getRawBits();
    return temp;
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    Fixed   temp(*this);
    temp._fixval -= other.getRawBits();
    return temp;
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    Fixed   temp(*this);
    temp._fixval *= other.getRawBits() >> bits;

    return temp;
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    Fixed   temp(*this);
    temp._fixval /= other.getRawBits() >> bits;
    return temp;
}

Fixed   &Fixed::operator++(void)
{
    _fixval += 1;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp(*this);

    _fixval += 1;
    return (temp);
}

Fixed   &Fixed::operator--(void)
{
    _fixval -= 1;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);
    
    _fixval -= 1;
    return temp;
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed     &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}
