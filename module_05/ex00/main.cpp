#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Bob", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
