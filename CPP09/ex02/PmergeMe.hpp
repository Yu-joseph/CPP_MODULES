#pragma once

#include  <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <ctime>
// #include <temp

// template <typename Container>

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
		// void vec_sort();

		// sort for vector
		std::vector<int> vec_sort(std::vector<int> vect);
		void addToWinners(std::vector<int>& winner, const std::vector<int>& losers, int odd);
		template <typename Container>
		void binaryInsert(Container& cont, int value);
		std::vector<size_t> getJacobsthalIndices(size_t size);
		void  sort_fn_deq();
		void deque_sort();
		/// use
		void fillPair(std::vector<std::pair<int, int> >& pairs, int& odd, std::vector<int> vect);
		void SplitNumbers(std::vector<std::pair<int, int> >& pairs, std::vector<int>& winner, std::vector<int>& loser);
		~PmergeMe();
};