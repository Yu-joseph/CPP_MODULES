#pragma once


#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& ls);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ls);
	void execute(Bureaucrat const & executor) const;
};
