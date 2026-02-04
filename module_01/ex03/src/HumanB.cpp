#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &n) : name(n), weapon(NULL) {}
HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}

void	HumanB::attack(void) const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack" << std::endl;
}
