#include "RPN.hpp"
#include <sstream>



RPN::RPN(){}

void RPN::parse_arg(std::string arg)
{
    std::stringstream ss(arg);
    std::string token;
    while (std::getline(ss, token, ' '))
    {
        if (token.empty())
            continue;
        std::cout << "--" + token + "--" << std::endl;
        if (token.size() == 1)
        {
            if (isdigit(token[0]))
            {
                std::cout << "this number" << std::endl;
            }
            else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
            {
                std::cout << "this operator" << std::endl;
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
}


RPN::~RPN(){}