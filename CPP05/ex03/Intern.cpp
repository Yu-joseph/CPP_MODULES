#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"


Intern::Intern(){}
Intern& Intern::operator=(const Intern& ls)
{
	(void)ls;
	return *this;
}

Intern::Intern(const Intern& ls)
{
	(void)ls;
}

AForm* Intern::CreatPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}
AForm* Intern::CreatShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
AForm* Intern::CreatRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}



AForm* Intern::makeForm(std::string form, std::string target)
{
    typedef AForm* (Intern::*FormCreator)(std::string);
    FormCreator jack[3] = {&Intern::CreatPresidential, &Intern::CreatRobotomy, &Intern::CreatShrubbery};
    std::string ar[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

    std::cout << "Form requested: " << form << ", Target: " << target << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "Checking form: " << ar[i] << std::endl;
        if (form == ar[i]) {
            std::cout << "Intern has created " << form << " form." << std::endl;
            return (this->*jack[i])(target);
        }
    }
    throw std::runtime_error(std::string("Error: Form not found  ") + form);
}

Intern::~Intern(){}