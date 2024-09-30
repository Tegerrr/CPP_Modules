#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkGradeAndSign(executor);
	std::ofstream outputFile(getTarget() + "_shrubbery");
	if (outputFile.is_open())
	{
		outputFile <<		"\
							       oxoxoo    ooxoo\n\
								 ooxoxo oo  oxoxooo\n\
								oooo xxoxoo ooo ooox\n\
								oxo o oxoxo  xoxxoxo\n\
								oxo xooxoooo o ooo\n\
									ooo\\oo\\  /o/o\n\
										\\  \\/ /\n\
										 |   /\n\
										 |  |\n\
										 | D|\n\
										 |  |\n\
										 |  |\n\
								  ______/____\\____\n";
	}
	outputFile.close();
}