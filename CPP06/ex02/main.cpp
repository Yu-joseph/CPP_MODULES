#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <exception>

Base * generate(void)
{
	std::srand(time(0));
	int s = std::rand() % 3;

	if (s == 0) {
        return new A();
    } else if (s == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p)
{
    // std::cout << "lslslsls" << std::endl;
	if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    }
	else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    }
	else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
	else {
        std::cout << "fieled to cast " << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
       A& a = dynamic_cast<A&>(p);
       (void)a;
       std::cout << "this is A Type" << std::endl;
       return ;
    }
    catch(const std::bad_cast& e){ }
    try
    {
       B& b = dynamic_cast<B&>(p);
       (void)b;
       std::cout << "this is B Type" << std::endl;
       return ;
    }
    catch(const std::bad_cast& e){}
    try
    {
       C& c = dynamic_cast<C&>(p);
       (void)c;
       std::cout << "this is C Type" << std::endl;
       return ;
    }
    catch(const std::bad_cast& e){ }
    std::cout << "Unknown type" << std::endl;
}
void ss()
{
    system("leaks random");
}
int main()
{
    Base* jack = generate();
    Base* j = generate();
    // atexit(ss);
    identify(jack);
    identify(*j);
    delete jack;
    return 0;
}