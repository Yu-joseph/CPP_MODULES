#pragma once

#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int max_size;
	std::vector<int> numb;
public:
	Span(unsigned int N);
	void addNumber(unsigned int x);
	~Span();
};


