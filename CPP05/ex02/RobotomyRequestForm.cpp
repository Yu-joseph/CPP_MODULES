#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
RobotomyRequestForm::RobotomyRequestForm(): AForm(72, 45, "target") ,target("target"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(72, 45, target), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ls) 
{
	*this = ls;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ls)
{
	if(this != &ls)
	{
		this->target = ls.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(this->getSigned() && executor.getGrad() <= this->getGradExc())
	{
		std::srand(std::time(0));
		int run = std::rand() % 100;
		std::cout << "GHGH" << std::endl;
		if(run % 2 == 0)
		{
			std::cout << "that " << this->target << " has been robotomized successfully" << std::endl;
		}
		else
		{
			std::cout << "that " << this->target << " Robotomized is now failed" << std::endl;
		}
	}
	else{
		throw std::runtime_error(std::string("RobotomyRequestForm::GradeTooLowException Or FormNotSigned"));
	}
}

RobotomyRequestForm::~RobotomyRequestForm(){}