#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");

	a.attack("Bravo");
	b.takeDamage(3);
	b.beRepaired(2);

	for (int i = 0; i < 11; ++i)
		a.attack("TargetDummy");

	b.takeDamage(100);
	b.attack("Alpha");
	b.beRepaired(1);

	return 0;
}
