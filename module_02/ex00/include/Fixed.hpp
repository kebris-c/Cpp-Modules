#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	public:
		/* Constructor */
		Fixed();
		/* Copy constructor */
		Fixed(const Fixed &other);
		/* Operator overload member function | Copy assignment operator */
		Fixed	&operator=(const Fixed &other);
		/* Destructor */
		~Fixed();

		/* Function members */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
