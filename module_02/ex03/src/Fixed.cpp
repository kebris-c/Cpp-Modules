#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int number) : _rawBits(number * (1 << _fractionalBits))
{
}

Fixed::Fixed(const float number)
	: _rawBits(static_cast<int>(roundf(number * (1 << _fractionalBits))))
{
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_rawBits = other._rawBits;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits / (1 << _fractionalBits));
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->_rawBits + other._rawBits);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->_rawBits - other._rawBits);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long product;

	product = static_cast<long>(this->_rawBits) * other._rawBits;
	result.setRawBits(static_cast<int>(product / (1 << _fractionalBits)));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long scaled;

	scaled = static_cast<long>(this->_rawBits) * (1 << _fractionalBits);
	result.setRawBits(static_cast<int>(scaled / other._rawBits));
	return (result);
}

Fixed &Fixed::operator++()
{
	++this->_rawBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);

	++this->_rawBits;
	return (copy);
}

Fixed &Fixed::operator--()
{
	--this->_rawBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);

	--this->_rawBits;
	return (copy);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
