#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(HIGHEST) {}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name), _grade(grade)
{
	if (_grade < HIGHEST)
		throw GradeTooHighException();
	else if (_grade > LOWEST)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	(*this) = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	_grade = other._grade;
	return *this;
}

std::string const &Bureaucrat::getName(void) const
{
	return _name;
}

int const &Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
	if ((_grade - 1) < HIGHEST)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if ((_grade + 1) > LOWEST)
		throw GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	std::cout << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;
	return out;
}
