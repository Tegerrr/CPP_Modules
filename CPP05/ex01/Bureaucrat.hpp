#ifndef Bureaucrat_hpp
# define Bureaucrat_hpp

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

#define LOWEST 150
#define HIGHEST 1

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int const grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);

		std::string const	&getName() const;
		int const			&getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form) const;

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
		std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif