#include "Span.hpp"

Span::Span(unsigned int N) : N(N){}


Span::Span( void ) : N(0) { }


Span::Span( const Span& ls ) : N(ls.N), sp(ls.sp) { }

Span& Span::operator=( const Span& ls ) {
	if (this != &ls) {
		this->N = ls.N;
		this->sp = ls.sp;
	}
	return *this;
}

void Span::addNumber(unsigned int nb)
{
	if (this->sp.size() >= N)
	{
		throw std::out_of_range(std::string("there is no space"));
	}
	this->sp.push_back(nb);
	
}

int Span::shortestSpan()
{
	int minspan = std::numeric_limits<int>::max();
	if (sp.size() < 2)
	{
		throw std::invalid_argument(std::string("should size be more than 1"));
	}
	else{
		std::vector<int> tmp(sp);
    	std::sort(tmp.begin(), tmp.end());
		for (size_t i = 0; i < tmp.size()-1 ; i++)
		{
			int def = tmp[i+1] - tmp[i];
			if (def < minspan)
			{
				minspan = def;
			}
		}
	}
	return minspan;
}

int	Span::longestSpan()
{
	int maxspn = 0;
	if (sp.size() < 2)
	{
		throw std::invalid_argument(std::string("should size be more than 1"));
	}
	std::vector<int> tmp(sp);
	std::sort(tmp.begin(), tmp.end());
	maxspn = tmp[tmp.size() - 1] - tmp[0];
	return maxspn;
}
void Span::addNumbers(const std::vector<int>& vec) {
    if (sp.size() + vec.size() > N) {
        throw std::out_of_range("Not enough space!");
    }
    sp.insert(sp.end(), vec.begin(), vec.end());
}


Span::~Span(){}