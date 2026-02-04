#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon
{
	private:
		std::string	type;
	public:
		/* Constructor / Destructor */
		Weapon(const std::string &t);
		~Weapon();
		/* Setter / Getter*/
		void				setType(const std::string &t);
		const std::string	&getType() const;
};

#endif
