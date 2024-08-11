#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;

	std::cout << "a = " << a << std::endl;
	try
	{
		Bureaucrat b("bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat c("steve", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat d;
		d.decrementGrade();
		std::cout << "decremented to " << d.getGrade() << std::endl;
		d.incrementGrade();
		d.incrementGrade();
		std::cout << "it's ok" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
