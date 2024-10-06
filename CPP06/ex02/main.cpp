#include "Base.hpp"

int main ()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	std::cout << "__________________\n" << std::endl;
	
	Base *base3 = new Base;
	identify(base3);
	identify(*base3);
	delete base3;
	return 0;
}
