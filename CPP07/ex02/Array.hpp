#pragma once 

#include <iostream>
#include <cstddef>
#include <cstddef>
#include <stdexcept>
template <typename T>
class Array
{
private:
	T* data;
	unsigned int s;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& ls);
	Array& operator=(const Array& ls);
	T& operator[](unsigned int index);
	T& operator[](unsigned int index) const;
	unsigned int size() const;
	~Array();
};

#include "Array.tpp"