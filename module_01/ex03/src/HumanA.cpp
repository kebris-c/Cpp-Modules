#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &n, Weapon &w) : name(n), weapon(w) {}
HumanA::~HumanA(void) {}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
