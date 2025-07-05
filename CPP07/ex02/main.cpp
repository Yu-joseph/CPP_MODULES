#include "Array.hpp"


int main()
{
	Array<int> s(4);
	s[0] = 0;
    s[1] = 1;
    s[2] = 2;
    s[3] = 4;
	std::cout << s[3] << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << "-------------------" << std::endl;
	Array<char> a(1);
	Array<char> c(3);
	try{

		c[0] = 'A';
		a[4] = 'M';
		a = c;
	}catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		// std::cout << a[0] << std::endl;
		// std::cout << a[1] << std::endl;
	}
	Array<std::string> jack;
	std::cout << jack.size() << std::endl;
	return 0;
}