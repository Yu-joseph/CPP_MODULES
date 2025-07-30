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
		// void vec_sort();
		//sort for the vector
		// template <typename Container>
		void addToWinners(std::vector<int>& winner, const std::vector<int>& losers, int odd);
		void sort_fn_vec();
		std::vector<int> vec_sort(std::vector<int> vect);
		void binaryInsert(std::vector<int>& cont, int value);
		std::vector<size_t> getJacobsthalIndices(size_t size);
		void fillPair(std::vector<std::pair<int, int> >& pairs, int& odd, std::vector<int> vect);
		void SplitNumbers(std::vector<std::pair<int, int> >& pairs, std::vector<int>& winner, std::vector<int>& loser);
		// sort for vector
		// deque **
		void  sort_fn_deq();
		std::deque<int> deque_sort(std::deque<int> deque);
		void fillPairDeque(std::deque<std::pair<int, int> >& pairs, int& odd, std::deque<int> vect);
		void SplitNumbersDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& winner, std::deque<int>& loser);
		void addToWinnersDeque(std::deque<int>& winner, const std::deque<int>& losers, int odd);
		std::deque<size_t> getJacobsthalIndicesDeque(size_t size);
		void binaryInsertDeque(std::deque<int>& cont, int value);
		/// use
		~PmergeMe();
};