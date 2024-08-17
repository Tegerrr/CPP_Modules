#include "Form.hpp"

Form::Form() :
	_name("default"),
	_signed(false), 
	_grade_sign(HIGHEST),
	_grade_exe(HIGHEST)
	{}

Form::Form(std::string name, int grade_sign, int grade_exe) :
	_name(name),
	_signed(false),
	_grade_sign(grade_sign),
	_grade_exe(grade_exe)
	{}

Form::~Form() {}

Form::Form(Form const &other) :
	_name(other._name),
	_signed(other._signed),
	_grade_sign(other._grade_sign),
	_grade_exe(other._grade_exe)
	{}

Form &Form::operator=(Form const &other)
{
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

void Form::beSigned(Bureaucrat const &to_sign)
{
	if (to_sign.getGrade() <= _grade_sign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade too high to sign form";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade too low to sign form";
}

int const &Form::getGradeSign() const { return _grade_sign; }

int const &Form::getGradeExe() const { return _grade_exe; }

bool Form::getSignature() const { return _signed; }

std::string const &Form::getName() const { return _name; }

std::ostream &operator<<(std::ostream &out, const Form &obj)
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