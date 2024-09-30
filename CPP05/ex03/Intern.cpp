#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
        return *this;
    return *this;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
	int i = 0;
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *newForm = NULL;

	if (target.empty())
        throw InvalidTarget();
	for(i = 0; i < 3; i++)
	{
		if (form == forms[i])
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form << std::endl;
			newForm = new ShrubberyCreationForm(target);
			break;
		case 1:
			std::cout << "Intern creates " << form << std::endl;
			newForm = new RobotomyRequestForm(target);
			break;
		case 2:
			std::cout << "Intern creates " << form << std::endl;
			newForm = new PresidentialPardonForm(target);
			break;
		default:
			throw InvalidForm();
	}	
	return newForm;
}

const char *Intern::InvalidForm::what() const throw()
{
    return ("Invalid form name");
}

const char *Intern::InvalidTarget::what() const throw()
{
    return ("Invalid target");
}
