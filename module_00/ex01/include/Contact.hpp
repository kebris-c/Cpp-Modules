#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>

class	Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darknestSecret;

	std::string	truncate(const std::string &str) const
	{
		if (str.length() > 10)
			return (str.substr(0, 9) + ".");
		else
			return (str);
	}

public:
	void	setFN(const std::string &fn);
	void	setLN(const std::string &ln);
	void	setNN(const std::string &nn);
	void	setPN(const std::string &pn);
	void	setDS(const std::string &ds);

	void	showTable() const;
	void	showRaw() const;
};

#endif
