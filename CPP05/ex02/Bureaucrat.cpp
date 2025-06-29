#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("NAME"), grade(150)
{
}


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

void Bureaucrat::signAForm(AForm& ls)
{
	try {
		ls.beSigned(*this);
		std::cout << this->getName() << " signed " << ls.getName() << std::endl;

	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn’t sign " << ls.getName() << " because " 
			<< e.what() << std::endl;
	}

	// if(ls.beSigned(*this) == true)
	// {
	// 	std::cout << this->getName() << " signed " << ls.getName() << std::endl;
	// }
	// else {
	// 	std::cout << this->getName() << " couldn’t sign " << ls.getName() << "cuz this grade " 
	// 		<< this->getGrad() << " is to low" << std::endl;
	// }
}
void Bureaucrat::executeForm(AForm const & form) const
{
	try{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << this->getName() << " couldn’t excute " << form.getName() << " because " 
			<< e.what() << std::endl;
	}
}
Bureaucrat::~Bureaucrat(){}