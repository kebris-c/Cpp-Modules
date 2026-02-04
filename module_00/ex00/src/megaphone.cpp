#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int		i;
	char	c;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		const std::string str(av[i]);
		for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
		{
			c = static_cast<char>(std::toupper(static_cast<unsigned char>(*it)));
			std::cout << c;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
