#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _grade_sign;
		int const _grade_exe;
		std::string _target;

	public:
		AForm();
		AForm(std::string name, int grade_sign, int _grade_exe);
		virtual ~AForm();
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);

		std::string const	&getName() const;
		int const			&getGradeSign() const;
		int const			&getGradeExe() const;
		bool				getSignature() const;
		std::string			getTarget() const;
		void				beSigned(Bureaucrat const &to_sign);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		void				checkGradeAndSign(Bureaucrat const & executor) const;
		void				setTarget(std::string const &target);

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
		std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif
