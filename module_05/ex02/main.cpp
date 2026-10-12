#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 70);
	Bureaucrat low("Low", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Ford Prefect");

	low.signForm(shrub);
	mid.signForm(shrub);
	mid.executeForm(shrub);

	low.executeForm(robo);
	boss.signForm(robo);
	boss.executeForm(robo);

	mid.signForm(pardon);
	boss.signForm(pardon);
	boss.executeForm(pardon);

	return 0;
}
