#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(25, 5, "target"), target("target"){} 

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(25, 5, target), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ls) 
{
	*this = ls;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ls)
{
	if(this != &ls)
	{
		this->target = ls.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() && executor.getGrad() <= this->getGradExc())
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else{
		throw std::runtime_error(std::string("ShrubberyCreationForm::GradeTooLowException Or FormNotSigned"));
	}
}

PresidentialPardonForm::~PresidentialPardonForm(){}