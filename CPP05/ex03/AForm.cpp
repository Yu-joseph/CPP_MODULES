#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm() : name("NAME"), sign(false), grad_sign(150), grad_exc(150)
{

}
AForm::~AForm(){}

AForm::AForm(const AForm& ls) : name(ls.name), sign(ls.sign), grad_sign(ls.grad_sign), grad_exc(ls.grad_exc)
{
	*this = ls;
}

AForm& AForm::operator=(const AForm& ls)
{
	if (this != &ls)
	{
		this->sign = ls.getSigned();
	}
	return (*this);
}

bool AForm::getSigned() const{
	return this->sign;
}

int AForm::getGradExc() const
{
	return this->grad_exc;
}
int AForm::getGradSign() const
{
	return this->grad_sign;
}

std::string AForm::getName() const
{
	return this->name;
}

AForm::AForm(int gs, int ge, std::string name_): name(name_), grad_sign(gs), grad_exc(ge)
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

std::ostream& operator<<(std::ostream& os, const AForm& ls)
{
	os << "AForm name is " << ls.getName() << "\n"
		<< "is the AForm signed :" << ((ls.getSigned()) ? "YES\n" : "NO\n")
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

void AForm::beSigned(Bureaucrat& ls)
{
	if (ls.getGrad() <= this->getGradSign())
	{
		this->sign = true;
	}
	else {
		throw std::runtime_error(std::string("AForm::GradeTooLowException."));
	}
}