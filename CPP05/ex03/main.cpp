#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(0));
	try
	{
		Bureaucrat dude("dude", 1);
		Intern junior;
		AForm *form;

		std::cout << "\n-Shrubbery-\n" << std::endl;
		form = junior.makeForm("shrubbery creation", "Shrubbery");
		dude.signForm(*form);
		dude.executeForm(*form);
		delete form;

		std::cout << "\n-Presidential-\n" << std::endl;
		form = junior.makeForm("presidential pardon", "Presidential");
		dude.signForm(*form);
		dude.executeForm(*form);
		delete form;

		std::cout << "\n-Robotomy-\n" << std::endl;
		form = junior.makeForm("robotomy request", "Robotomy");
		dude.signForm(*form);
		dude.executeForm(*form);
		delete form;

		std::cout << "\n-Invalid form-\n" << std::endl;
		form = junior.makeForm("invalid form", "Invalid");
		dude.signForm(*form);
		dude.executeForm(*form);
		delete form;

		std::cout << "\n-Invalid target-\n" << std::endl;
		form = junior.makeForm("shrubbery creation", "");
		dude.signForm(*form);
		dude.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
