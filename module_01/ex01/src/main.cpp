#include "Zombie.hpp"

int	main(void)
{
	int		i;
	int		N;
	Zombie	*horde;

	N = 5;
	horde = zombieHorde(N, "HordeZombie");
	i = 0;
	while (i < N)
		horde[i++].announce();
	delete[] horde;
	return (0);
}
