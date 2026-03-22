#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("Ruby");

	d.whoAmI();
	d.attack("Target");
	d.guardGate();
	d.highFivesGuys();

	d.takeDamage(20);
	d.beRepaired(10);

	DiamondTrap copy(d);
	copy.whoAmI();

	return 0;
}
