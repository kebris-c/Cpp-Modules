#include "Zombie.hpp"
#include <sstream>
#include <iostream>

Zombie	*zombieHorde(int N, std::string name)
{
	int					i;
	Zombie				*horde;
	std::string			uniqueName;
	std::ostringstream	oss;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		oss.str("");
		oss.clear();
		oss << name << (i + 1);
		uniqueName = oss.str();
		horde[i].setName(uniqueName);
		std::cout << "Zombie " << uniqueName << " is created" << std::endl;
		i++;
	}
	return (horde);
}
