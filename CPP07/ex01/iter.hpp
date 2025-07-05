#pragma once

#include <iostream>

template <typename AR> 

void iter(AR *array, size_t lenght, void (*func)(AR&))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}

template <typename AR>   

void iter(AR *array, size_t lenght, void (*func)(const AR&))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}