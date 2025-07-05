#include "Array.hpp"

template <typename T>

Array<T>::Array()
{
	this->s = 0;
	this->data = nullptr;
}

template <typename T>

Array<T>::Array(unsigned int n)
{
	this->s = n;
	this->data = new T[n]();
}

template <typename T>

Array<T>::Array(const Array& ls)
{
	this->s = ls.s;
	this->data = new T[this->s];
	for (size_t i = 0; i < ls.s; i++)
	{
		this->data[i] = ls.data[i];
	}
	
}

template <typename T>

Array<T>& Array<T>::operator=(const Array& ls)
{
	if(this != &ls)
	{
		delete[] this->data;
		this->s = ls.s;
		this->data = new T[this->s];
		for (size_t i = 0; i < ls.s; i++)
		{
			this->data[i] = ls.data[i];
		}
	}
	return *this;
}


template <typename T>

T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->s)
	{
		throw std::out_of_range("Out of the range");
	}
	return this->data[index];
}

template <typename T>

T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->s)
	{
		throw std::out_of_range("Out of the range");
	}
	return this->data[index];
}

template <typename T>

unsigned int Array<T>::size() const
{
	return this->s;
}

template <typename T>

Array<T>::~Array(){}