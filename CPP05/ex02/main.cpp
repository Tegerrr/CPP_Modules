#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	srand(time(0));
	try
	{
		Bureaucrat dude("dude", 1);
		ShrubberyCreationForm form1("Shrubbery");
		PresidentialPardonForm form2("Presidential");
		RobotomyRequestForm form3("Robotomy");

		std::cout << "\n-Shrubbery-\n" << std::endl;
		dude.signForm(form1);
		dude.executeForm(form1);

		std::cout << "\n-Presidential-\n" << std::endl;
		dude.signForm(form2);
		dude.executeForm(form2);

		std::cout << "\n-Robotomy-\n" << std::endl;
		dude.signForm(form3);
		dude.executeForm(form3);
		dude.executeForm(form3);
		dude.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
