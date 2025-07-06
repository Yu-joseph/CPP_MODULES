#include "Span.hpp"

// int main()
// {
// 	try {
// 		Span jack(4);
// 		jack.addNumber(9);
// 		jack.addNumber(7);
// 		jack.addNumber(-1);
// 		jack.addNumber(100);
// 		std::cout << jack.shortestSpan() << std::endl;
// 		std::cout << jack.longestSpan() << std::endl;
// 		// jack.addNumber(1);
// 	}
// 	catch(std::exception & e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }

// 3 6 9 11 17



int main()
{
	try{
		Span sp = Span(20);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "************************" << std::endl;
		std::vector<int> jack(3);
		jack[0] = 10;
		jack[1] = 20;
		jack[2] = 30;
		sp.addNumbers(jack);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}