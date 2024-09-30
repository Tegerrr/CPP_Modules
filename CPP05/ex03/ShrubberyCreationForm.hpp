#ifndef ShrubberyCreationForm_hpp
# define ShrubberyCreationForm_hpp

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

		void		execute(Bureaucrat const & executor) const;
};

#endif