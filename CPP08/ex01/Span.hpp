#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
private:
	unsigned int N; //max int
	std::vector<int> sp;
public:
	Span(unsigned int N);
	Span(void);
	Span& operator=( const Span& ls );
	Span( const Span& ls );
	void addNumber(unsigned int x);
	int shortestSpan();
	~Span();
};


