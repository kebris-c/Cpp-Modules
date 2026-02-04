#include "Contact.hpp"

void	Contact::setFN(const std::string &fn)
{
	firstName = fn;
}

void	Contact::setLN(const std::string &ln)
{
	lastName = ln;
}

void	Contact::setNN(const std::string &nn)
{
	nickName = nn;
}

void	Contact::setPN(const std::string &pn)
{
	phoneNumber = pn;
}

void	Contact::setDS(const std::string &ds)
{
	darknestSecret = ds;
}

void	Contact::showTable() const
{
	std::cout << std::setw(10) << truncate(firstName) << "|" \
		<< std::setw(10) << truncate(lastName) << "|" \
		<< std::setw(10) << truncate(nickName) << std::endl;
}

void	Contact::showRaw() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darknest secret: " << darknestSecret << std::endl;
}
