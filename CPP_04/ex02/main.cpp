#include "Dog.hpp"
#include "Cat.hpp"
#include <string>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	
	std::cout << std::endl;

	Animal *str[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			str[i] = new Dog();
		else
			str[i] = new Cat();
	}

	Brain *dog_brain[2];
	Brain *cat_brain[2];

	dog_brain[0] = str[0]->GetBrain();
	dog_brain[0]->GetIdeas()[0] = "Dog idea";
	*str[1] = *str[0];
	dog_brain[1] = str[1]->GetBrain();

	cat_brain[0] = str[2]->GetBrain();
	cat_brain[0]->GetIdeas()[0] = "Cat idea";
	*str[3] = *str[2];
	cat_brain[1] = str[3]->GetBrain();

	std::cout << dog_brain[0]->GetIdeas()[0] << std::endl;
	std::cout << dog_brain[1]->GetIdeas()[0] << std::endl;

	std::cout << cat_brain[0]->GetIdeas()[0] << std::endl;
	std::cout << cat_brain[1]->GetIdeas()[0] << "\n" << std::endl;

	str[0]->makeSound();
	str[3]->makeSound();
	std::cout << str[0]->getType() << std::endl;
	std::cout << str[3]->getType() << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete str[i];
	}

	return 0;
}
