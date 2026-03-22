#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat chief("Chief", 1);
	Bureaucrat intern("Intern", 150);
	Form budget("BudgetForm", 50, 25);

	std::cout << chief << std::endl;
	std::cout << intern << std::endl;
	std::cout << budget << std::endl;

	intern.signForm(budget);
	chief.signForm(budget);
	std::cout << budget << std::endl;

	try
	{
		Form invalid("Invalid", 0, 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
