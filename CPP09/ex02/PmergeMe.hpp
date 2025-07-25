#pragma once

#include  <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> vec;
    	std::deque<int> deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& ls);
		PmergeMe& operator=(const PmergeMe& ls);
		void checkNb(char **nb);
		void fill_nb(std::string nb);
		std::string trim(const std::string &str);
		void sort_fn_vec();
		void vec_sort();
		void sort_fn_deq();
		void deque_sort();
		~PmergeMe();
};