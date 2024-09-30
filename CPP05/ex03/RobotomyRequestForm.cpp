#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkGradeAndSign(executor);
	std::cout << getTarget() << "* INTENSE DRILLING NOIZES *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getTarget() << " robotomy failed" << std::endl;
}