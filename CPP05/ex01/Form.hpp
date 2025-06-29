#pragma once

#include <iostream>
// #include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool sign;
	const int grad_sign;
	const int grad_exc;
public:
	Form(const Form& ls);
	Form(int gs, int ge, std::string name_);
	Form();
	~Form();
	Form& operator=(const Form& ls);
	bool getSigned() const;
	int getGradSign() const;
	int getGradExc() const;
	std::string getName() const;
	void beSigned(Bureaucrat& ls);
};

std::ostream& operator<<(std::ostream& os, const Form& ls);