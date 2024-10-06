# include "Base.hpp"

Base*	generate()
{
	srand(time(NULL));
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "A class generated" << std::endl;
			return new A;
		case 1:
			std::cout << "B class generated" << std::endl;
			return new B;
		case 2:
			std::cout << "C class generated" << std::endl;
			return new C;
	}
		return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "arg is A class (*)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "arg is B class (*)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "arg is C class (*)" << std::endl;
	else
		std::cout << "arg is not any class! (*)" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "arg is A class (&)" << std::endl;
	}
	catch (std::bad_cast &e) { std::cerr << "arg is not class A " << e.what() << std::endl; }
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "arg is B class (&)" << std::endl;
	}
	catch (std::bad_cast &e) { std::cerr << "arg is not class B " << e.what() << std::endl; }
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "arg is C class (&)" << std::endl;
	}
	catch (std::bad_cast &e) { std::cerr << "arg is not class C " << e.what() << std::endl;; }
}