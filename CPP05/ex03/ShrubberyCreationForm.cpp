#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(): AForm(145, 137, "target"), target("target"){} 

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(145, 137, target), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ls) 
{
	*this = ls;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ls)
{
	if(this != &ls)
	{
		this->target = ls.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	// std::cout << this->getGradExc() << std::endl;
	// std::cout << executor.getGrad() << std::endl;
	if(this->getSigned() && executor.getGrad() <= this->getGradExc())
	{
		// std::cout << "thshshhsshshs" << std::endl;
		std::ofstream file(target + "_shrubbery");
		if (!file.is_open())
		{
			throw std::runtime_error(std::string("ERROR OPENING THE FILE"));
		}
		file << "       _-_       \n";
		file << "    /~~   ~~\\   \n";
		file << " /~~         ~~\\ \n";
		file << "{               }\n";
		file << " \\  _-     -_  / \n";
		file << "   ~  \\\\ //  ~  \n";
		file << "_- -   | | _- _  \n";
		file << "  _ -  | |   -_  \n";
		file << "      // \\\\      \n";
		file.close();
	}
	else{
		throw std::runtime_error(std::string("ShrubberyCreationForm::GradeTooLowException Or FormNotSigned"));
	}
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}