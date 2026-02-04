#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie " << this->name << " is created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << " is destroyed" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
