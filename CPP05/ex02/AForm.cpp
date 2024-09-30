#include "AForm.hpp"

AForm::AForm() :
	_name("default"),
	_signed(false), 
	_grade_sign(HIGHEST),
	_grade_exe(HIGHEST)
	{}

AForm::AForm(std::string name, int grade_sign, int grade_exe) :
	_name(name),
	_signed(false),
	_grade_sign(grade_sign),
	_grade_exe(grade_exe)
	{}

AForm::~AForm() {}

AForm::AForm(AForm const &other) :
	_name(other._name),
	_signed(other._signed),
	_grade_sign(other._grade_sign),
	_grade_exe(other._grade_exe)
	{}

AForm &AForm::operator=(AForm const &other)
{
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

void AForm::beSigned(Bureaucrat const &to_sign)
{
	if (to_sign.getGrade() <= _grade_sign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade too high to sign";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade too low to sign";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

int const &AForm::getGradeSign() const { return _grade_sign; }

int const &AForm::getGradeExe() const { return _grade_exe; }

bool AForm::getSignature() const { return _signed; }

std::string const &AForm::getName() const { return _name; }

void AForm::setTarget(std::string const &target)
{
	_target = target;
}

std::string AForm::getTarget() const
{
	return _target;
}

void AForm::checkGradeAndSign(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExe())
		throw GradeTooLowException();
	if (getSignature() == false)
		throw FormNotSignedException();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	std::cout << "-----\n" << obj.getName() << "\nsign grade: " << obj.getGradeSign() <<
		"\nexecution grade: " << obj.getGradeExe() << "\nis: ";
	if (obj.getSignature() == true)
		std::cout << "signed" << std::endl;
	else
		std::cout << "not signed" << std::endl;
	std::cout << "-----" << std::endl;
	return out;
}