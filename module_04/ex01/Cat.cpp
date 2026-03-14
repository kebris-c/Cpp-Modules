#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}
