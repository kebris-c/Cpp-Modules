#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap basic("Basic");
	ScavTrap guard("Guardian");

	basic.attack("Guardian");
	guard.takeDamage(2);

	guard.attack("Basic");
	guard.guardGate();

	for (int i = 0; i < 52; ++i)
		guard.attack("target");

	return 0;
}
