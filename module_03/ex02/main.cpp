#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap c("Clappy");
	ScavTrap s("Scavy");
	FragTrap f("Fraggy");

	c.attack("Scavy");
	s.attack("Fraggy");
	f.attack("Clappy");

	s.guardGate();
	f.highFivesGuys();

	f.takeDamage(50);
	f.beRepaired(10);
	f.takeDamage(500);
	f.attack("Nobody");

	return 0;
}
