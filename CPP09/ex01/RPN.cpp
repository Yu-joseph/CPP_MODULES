#include "RPN.hpp"
#include <sstream>



RPN::RPN(){}

RPN::RPN(const RPN& ls)
{
	(void)ls;
}

RPN& RPN::operator=(const RPN& ls)
{
	(void)ls;
	return *this;
}

void RPN::parse_arg(std::string arg)
{
    std::stringstream ss(arg);
    std::string token;
    int sz = 0;
    while (std::getline(ss, token, ' '))
    {
        if (token.empty())
            continue;
        if (token.size() == 1)
        {
            if (isdigit(token[0]))
            {
                add_elem(token);
            }
            else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
            {
                do_math(token);
                sz++;
            }
            else if (sz >= (int)this->stack.size())
            {
                throw std::out_of_range("more operators then we need");
            }
            
            else
            {
                throw std::out_of_range("Error: invalid character");
            }
        }
        else
        {
            throw std::out_of_range("Error: invalid format");
        }
    }
    if (sz == 0)
    {
        throw std::out_of_range("Error: messing operator");
    }
    if (this->stack.size() != 1)
    {
        throw std::out_of_range("Error: messing something");
    }
    
    std::cout << this->stack.top() << std::endl;

}

void RPN::add_elem(std::string n)
{
    std::stringstream ss(n);
    double nb = 0;
    ss >> nb;
    this->stack.push(nb);
}

void RPN::do_math(std::string nb)
{
    if (this->stack.size() < 2)
    {
        throw std::out_of_range("Error: invalid RPN format");
    }
    double a = this->stack.top();
    this->stack.pop();
    double b = this->stack.top();
    this->stack.pop();
    switch (nb[0])
    {
    case '*':
        this->stack.push(b * a);
        break;
    case '-':
        this->stack.push(b - a);
        break;
    case '+':
        this->stack.push(b + a);
        break;
    case '/':
        if (a == 0)
            throw std::out_of_range("ERROR in '/'");
        this->stack.push(b / a);
        break;
    
    default:
        break;
    }
}


RPN::~RPN(){}