#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form() : name("NAME"), sign(false), grad_sign(150), grad_exc(150)
{

}
Form::~Form(){}

Form::Form(const Form& ls) : name(ls.name), sign(ls.sign), grad_sign(ls.grad_sign), grad_exc(ls.grad_exc)
{
	*this = ls;
}

Form& Form::operator=(const Form& ls)
{
	if (this != &ls)
	{
		this->sign = ls.getSigned();
	}
	return (*this);
}

bool Form::getSigned() const{
	return this->sign;
}

int Form::getGradExc() const
{
	return this->grad_exc;
}
int Form::getGradSign() const
{
	return this->grad_sign;
}

std::string Form::getName() const
{
	return this->name;
}

Form::Form(int gs, int ge, std::string name_): name(name_), grad_sign(gs), grad_exc()
{
	if (gs > 150 || ge > 150)
	{
		throw std::runtime_error("Bureaucrat::GradeTooLowException");
	}
	else if(gs < 1 || ge < 1)
	{
		throw std::runtime_error("Bureaucrat::GradeTooHighExcept");
	}
}

std::ostream& operator<<(std::ostream& os, const Form& ls)
{
	os << "Form name is " << ls.getName() << "\n"
		<< "is the Form signed :" << ((ls.getSigned()) ? "YES\n" : "NO\n")
		<< "Grade sign is " << ls.getGradSign() << "\n"
		<< "grade required to execute" << ls.getGradExc() << std::endl;
	return os;
}

// void From::beSigned(const Bureaucrat& ls )
// {
// 	if(ls.getGrad() <= this.getGradSign())
// 	{
		 
// 	}
// }

void Form::beSigned(Bureaucrat& ls)
{
	if (ls.getGrad() <= this->getGradSign())
	{
		this->sign = true;
	}
	else {
		throw std::runtime_error(std::string("Form::GradeTooLowException."));
	}
}