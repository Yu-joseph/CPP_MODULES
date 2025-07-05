#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>

typename T::iterator easyfind(T &w, int nb)
{
	typename T::iterator it = std::find(w.begin(), w.end(), nb);
	    if (it == w.end())
        throw std::runtime_error("Value not found");
    return it;
}