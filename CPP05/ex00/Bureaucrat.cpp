#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("NAME"), grade(150)
{
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(int grad, const std::string name_) : name(name_)
{
	if (grad > 150)
	{
		throw std::runtime_error("Bureaucrat::GradeTooLowException");
	}
	else if(grad < 1)
	{
		throw std::runtime_error("Bureaucrat::GradeTooHighExcept");
	}
	this->grade = grad;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ls)
{
	if (this != &ls)
		this->grade = ls.getGrad();
	return *this; 
}

Bureaucrat::Bureaucrat(const Bureaucrat& ls) : name(ls.name) , grade(ls.getGrad())
{
}

int Bureaucrat::getGrad() const
{
	return this->grade;
}
std::string Bureaucrat::getName()const{return this->name;}

void Bureaucrat::incr()
{
	this->grade--;
	if (this->grade < 1)
	{
		throw std::runtime_error(std::string("Bureaucrat::GradeTooHighException"));
	}
}
void Bureaucrat::decrm()
{
	this->grade++;
	if (this->grade > 150)
	{
		throw std::runtime_error(std::string("Bureaucrat::GradeTooLowException."));
	}
}

std::ostream& operator<<(std::ostream& os ,const Bureaucrat& ls)
{
	os << ls.getName() << " , bureaucrat grade " << ls.getGrad() <<  ".";
	return os;
}