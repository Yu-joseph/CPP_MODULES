#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{

	Bureaucrat ls;
	std::cout << ls.getGrad() << std::endl;
	Bureaucrat jack(11, "jack");
	Form k(40, 70, "yssf");
	// k.beSigned(jack);
	jack.signForm(k);
	std::cout << "**********************" << std::endl;
	Bureaucrat n(130, "nGUY");
	Form mrino(70, 70, "morino");
	n.signForm(mrino);
	// Bureaucrat l(12, "jack");
	// std::cout << l << std::endl;
	// l.decrm();
	// std::cout << l << std::endl;
	// l.incr();
	// std::cout << l << std::endl;
	// try
	// {
	// 	Bureaucrat s(20, "Nma");
	// 	std::cout << s.getName() << std::endl;
	// 	printf("jack\n");
	// 	Bureaucrat a(0, "loris");
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	return 0;
}
