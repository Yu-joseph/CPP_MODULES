#pragma once


#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& ls);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ls);
	void execute(Bureaucrat const & executor) const;
};
