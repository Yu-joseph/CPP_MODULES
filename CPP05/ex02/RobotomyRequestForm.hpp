#pragma once


#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& ls);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ls);
	void execute(Bureaucrat const & executor) const;
};

