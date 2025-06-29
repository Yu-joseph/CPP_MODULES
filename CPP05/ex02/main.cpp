#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try{
		Bureaucrat ls(10, "arthur");
		ShrubberyCreationForm art("morgan");
		ls.signAForm(art);
		ls.executeForm(art);
		// art.beSigned(ls);
		// art.execute(ls);
		std::cout << "--------------------" << std::endl;
		Bureaucrat pi(22, "Lb4dadi");
		RobotomyRequestForm jik("CR0");
		pi.signAForm(jik);
		pi.executeForm(jik);
		// jik.beSigned(pi);
		// jik.execute(pi);
		std::cout << "--------------------" << std::endl;
		Bureaucrat q(24, "qqqqqq");
		PresidentialPardonForm Shevchenko("Shevchenko");
		q.signAForm(Shevchenko);
		q.executeForm(Shevchenko);
		
		// Shevchenko.beSigned(q);
		// Shevchenko.execute(q);
		//****************************************
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
