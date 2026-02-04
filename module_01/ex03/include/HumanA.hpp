#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class	HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		/* Constructor / Destructor */
		HumanA(const std::string &n, Weapon &w);
		~HumanA();
		/* Member Function */
		void	attack() const;
};

#endif
