#pragma once

#include <iostream>
#include <exception>
#include <stack>


class RPN
{
private:
	std::stack<double> stack;
public:
	RPN();
	RPN(const RPN& ls);
	RPN& operator=(const RPN& ls);
	 void parse_arg(std::string arg);
	 void do_math(std::string nb);
	 void add_elem(std::string n);
	~RPN();
};

