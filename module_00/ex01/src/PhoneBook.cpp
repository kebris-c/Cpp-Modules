#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), nContacts(0) {}

void	PhoneBook::addContact(const Contact &contact)
{
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % 8;
	if (nContacts < 8)
		nContacts++;
}

void	PhoneBook::showContacts() const
{
	int	i;

	std::cout << std::setw(10) << "Index" << "|" \
		<< std::setw(10) << "First name" << "|" \
		<< std::setw(10) << "Last name" << "|" \
		<< std::setw(10) << "Nickname" << std::endl;
	i = 0;
	while (i < nContacts)
	{
		std::cout << std::setw(10) << i << "|";
		contacts[i].showTable();
		i++;
	}
}

void	PhoneBook::showContact(int index) const
{
	if (index < 0 || index >= nContacts)
	{
		std::cout << "[!] Invalid index" << std::endl;
		return ;
	}
	contacts[index].showRaw();
}
