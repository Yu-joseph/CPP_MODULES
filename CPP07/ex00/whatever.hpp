#pragma once

#include <iostream>

template <typename sp>

void swap(sp &a, sp &b)
{
	sp temp = a;
	a = b;
	b = temp;
}


template <typename T>

T min(T a, T b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

template <typename mx>

mx max(mx a, mx b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}