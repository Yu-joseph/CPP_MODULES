#pragma once

#include <iostream>
#include <exception>
#include <stack>


class RPN
{
private:
	std::stack<int> stack;
public:
	static void parse_arg(std::string arg);
	RPN();
	~RPN();
};

