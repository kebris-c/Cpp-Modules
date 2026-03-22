#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
  private:
	static AForm *createShrubbery(const std::string &target);
	static AForm *createRobotomy(const std::string &target);
	static AForm *createPresidential(const std::string &target);

  public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &name, const std::string &target) const;

	class FormDoesNotExistException : public std::exception
	{
	  public:
		const char *what() const throw();
	};
};

#endif
