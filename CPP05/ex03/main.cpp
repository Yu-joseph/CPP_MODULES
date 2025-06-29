#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
// void ls()
// {
// 	system("leaks Bureaucrat");
// }
int main()
{
	// atexit(ls);
	try{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
