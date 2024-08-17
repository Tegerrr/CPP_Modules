#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _grade_sign;
		int const _grade_exe;

	public:
		Form();
		Form(std::string name, int grade_sign, int _grade_exe);
		~Form();
		Form(Form const &other);
		Form &operator=(Form const &other);

		std::string const	&getName() const;
		int const			&getGradeSign() const;
		int const			&getGradeExe() const;
		bool				getSignature() const;
		void				beSigned(Bureaucrat const &to_sign);

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};
		std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif
