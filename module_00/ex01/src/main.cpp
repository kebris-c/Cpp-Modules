#include "PhoneBook.hpp"

static void	cmd_add(PhoneBook& pbook)
{
	Contact		contact;
	std::string	input;

	std::cout << "First name: ";
	if (!std::getline(std::cin, input))
		return ;
	contact.setFN(input);

	std::cout << "Last name: ";
	if (!std::getline(std::cin, input))
		return ;
	contact.setLN(input);

	std::cout << "Nickname: ";
	if (!std::getline(std::cin, input))
		return ;
	contact.setNN(input);

	std::cout << "Phone number: ";
	if (!std::getline(std::cin, input))
		return ;
	contact.setPN(input);

	std::cout << "Darknest secret: ";
	if (!std::getline(std::cin, input))
		return ;
	contact.setDS(input);

	pbook.addContact(contact);
}

static void	cmd_search(PhoneBook& pbook)
{
	int	index;

	pbook.showContacts();
	std::cout << "Enter index to view full contact: ";
	if (!(std::cin >> index))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "[!] Invalid input" << std::endl;
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	pbook.showContact(index);
}

int	main(void)
{
	PhoneBook	pbook;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "ADD")
			cmd_add(pbook);
		else if (cmd == "SEARCH")
			cmd_search(pbook);
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "[!] Unknown command" << std::endl;
	}
	return (0);
}
