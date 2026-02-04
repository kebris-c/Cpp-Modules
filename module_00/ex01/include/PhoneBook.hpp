#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
private:
	Contact	contacts[8];
	int		nextIndex;
	int		nContacts;

public:
	PhoneBook();

	void	addContact(const Contact &contact);

	void	showContacts() const;
	void	showContact(int index) const;
};

#endif
