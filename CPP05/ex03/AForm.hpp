#pragma once

#include <iostream>
// #include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int grad_sign;
	const int grad_exc;
public:
	AForm(const AForm& ls);
	AForm(int gs, int ge, std::string name_);
	AForm();
	AForm& operator=(const AForm& ls);
	bool getSigned() const;
	int getGradSign() const;
	int getGradExc() const;
	void beSigned(Bureaucrat& ls);
	std::string getName() const;
	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual ~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& ls);