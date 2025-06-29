#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat l(12, "jack");
	std::cout << l << std::endl;
	l.decrm();
	std::cout << l << std::endl;
	l.incr();
	std::cout << l << std::endl;
	try
	{
		Bureaucrat s(20, "Nma");
		std::cout << s.getName() << std::endl;
		Bureaucrat a(0, "loris");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
