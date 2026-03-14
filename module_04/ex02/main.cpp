#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	Dog original;
	original.setIdea(0, "Guard home");
	Dog clone(original);
	original.setIdea(0, "Eat snacks");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Clone idea   : " << clone.getIdea(0) << std::endl;

	return 0;
}
