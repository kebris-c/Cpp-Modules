#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int count = 10;
	Animal *zoo[count];

	std::cout << "=== Building zoo ===" << std::endl;
	for (int i = 0; i < count / 2; ++i)
		zoo[i] = new Dog();
	for (int i = count / 2; i < count; ++i)
		zoo[i] = new Cat();

	std::cout << "\n=== Clearing zoo through Animal* ===" << std::endl;
	for (int i = 0; i < count; ++i)
		delete zoo[i];

	std::cout << "\n=== Subject basic test ===" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;

	std::cout << "\n=== Deep copy test ===" << std::endl;
	Dog original;
	original.setIdea(0, "Protect the house");
	Dog copy = original;
	original.setIdea(0, "Chase the cat");

	std::cout << "Original dog idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copied dog idea  : " << copy.getIdea(0) << std::endl;

	Cat c1;
	c1.setIdea(1, "Sleep on keyboard");
	Cat c2;
	c2 = c1;
	c1.setIdea(1, "Ignore humans");

	std::cout << "Original cat idea: " << c1.getIdea(1) << std::endl;
	std::cout << "Assigned cat idea: " << c2.getIdea(1) << std::endl;

	return 0;
}
