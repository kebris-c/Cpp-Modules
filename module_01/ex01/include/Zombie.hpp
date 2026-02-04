#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	name;
	public:
		/* Default constructor / Parametered constructor / Destructor */
		Zombie();
		Zombie(std::string name);
		~Zombie();

		/* Setters / Getters */
		void	setName(std::string name);

		/* Class's functions or methods */
		void	announce(void) const;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
