#pragma once

#include "AForm.hpp"
#include <iostream>


class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(int grad, const std::string name_);
	Bureaucrat(const Bureaucrat& ls);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& ls);
	int getGrad() const;
	std::string getName() const;
	void incr();
	void decrm();
	void signAForm(AForm& ls);
	void executeForm(AForm const & form) const;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& ls);
 

