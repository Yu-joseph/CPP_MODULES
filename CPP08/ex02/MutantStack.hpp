#pragma once


#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    ~MutantStack() {}
	MutantStack& operator=(const MutantStack& other)
	{
        std::stack<T>::operator=(other);
        return *this;
	}
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

