#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z;

	z = newZombie("HeapZombie");
	z->announce();
	randomChump("StackZombie");
	delete z;
	return (0);
}
