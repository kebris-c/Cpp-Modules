#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class	HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		/* Constructor / Destructor */
		HumanB(const std::string &n);
		~HumanB();
		/* Setter / Getter */
		void	setWeapon(Weapon &w);
		/* Member Function */
		void	attack() const;
};

#endif
