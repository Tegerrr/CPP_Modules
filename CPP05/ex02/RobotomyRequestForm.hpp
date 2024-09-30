#ifndef RobotomyRequestForm_hpp
# define RobotomyRequestForm_hpp

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

		void		execute(Bureaucrat const & executor) const;
};

#endif