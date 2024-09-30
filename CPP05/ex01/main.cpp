#include "Bureaucrat.hpp"

int main()
{
	Form	form("exam", 5, 3);
	try
	{
		Bureaucrat a("Stan", 4);
		a.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "hi" << std::endl;
	}

	std::cout << form << std::endl;

	return 0;
}
