#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& ls)
{
	(void)ls;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& ls)
{
	(void)ls;
	return *this;
}

//
std::string PmergeMe::trim(const std::string &str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
//
void PmergeMe::checkNb(char **nb)
{
	int i = 1;
	while(nb[i])
	{
		// std::cout << "where" << std::endl;
		std::string trimmed = trim(std::string(nb[i]));
		fill_nb(std::string(trimmed));
		i++;
	}
}

void PmergeMe::fill_nb(std::string nb)
{
	std::stringstream ss(nb);
	int x = 0;
	if (!(ss >> x) || !ss.eof() || x < 0)
	{
		throw std::out_of_range("Error not valid number");
	}
	// std::cout << x << std::endl;
	this->deq.push_back(x);
	this->vec.push_back(x);
	
}

void PmergeMe::sort_fn_vec()
{
	std::cout << "before: ";
    for (size_t i = 0; i < this->vec.size(); ++i)
        std::cout << this->vec[i] << " ";
    std::cout << std::endl;
	clock_t start = clock();
	//
	std::cout << "after :" ;
	std::vector<int> storted = vec_sort(this->vec);
	for (size_t i = 0; i <storted.size(); ++i)
        std::cout <<storted[i] << " ";
    std::cout << std::endl;
	//
	clock_t end = clock();
	double time_us = (end - start) * 1e6 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->vec.size() 
	<< " elements with std::vector : " << time_us << "us" << std::endl;
    // std::cout << "Deque: ";
    // for (size_t i = 0; i < this->deq.size(); ++i)
    //     std::cout << this->deq[i] << " ";
    // std::cout << std::endl;
}

void PmergeMe::fillPair(std::vector<std::pair<int, int> >& pairs, int& odd, std::vector<int> vect)
{
	size_t size = vect.size();
	if (size % 2 != 0)
	{
		odd = vect[size - 1];
		size -= 1;
	}
	else
	{
		odd = -1;
	}

	for (size_t i = 0; i < size; i += 2)
	{

		if (vect[i] < vect[i+1])
		{
			std::pair<int, int> pr(vect[i+1], vect[i]);
			pairs.push_back(pr);
		}
		else{
			std::pair<int, int> pr(vect[i], vect[i + 1]);
			pairs.push_back(pr);
		}
		
	}
}

std::vector<int> PmergeMe::vec_sort(std::vector<int> vect)
{
	std::vector<int> winner, losers;
	std::vector<std::pair<int, int> > pairs;
	int odd;
	odd = -1;
	if (vect.size() == 1)
		return vect;
	fillPair(pairs, odd, vect);
	SplitNumbers(pairs, winner, losers);
	winner = vec_sort(winner);
	addToWinners(winner, losers, odd);
	return winner;
}

// template <typename Container>

void PmergeMe::binaryInsert(std::vector<int>& cont, int value)
{
    std::vector<int>::iterator pos = std::lower_bound(cont.begin(), cont.end(), value);
    cont.insert(pos, value);
}


void PmergeMe::addToWinners(std::vector<int>& winner, const std::vector<int>& losers, int odd)
{
	// std::cout << "*****" ;
	std::vector<size_t> insertOrder = getJacobsthalIndices(losers.size());
	// for (size_t i = 0; i < insertOrder.size(); i++)
	// {
	// 	std::cout << insertOrder[i];
	// }
	// std::cout << "****" << std::endl;
    for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		size_t index = insertOrder[i];
        if (index < losers.size())
            binaryInsert(winner, losers[index]);
	}
	std::vector<size_t> insertedIndices(insertOrder.begin(), insertOrder.end());
    for (size_t i = 0; i < losers.size(); ++i)
    {
        if (std::find(insertedIndices.begin(), insertedIndices.end(), i) == insertedIndices.end())
            binaryInsert(winner, losers[i]);
    }
    if (odd != -1)
        binaryInsert(winner, odd);
}

// algo fordjhnson
// numbers jackobstal



std::vector<size_t> PmergeMe::getJacobsthalIndices(size_t size)
{
	size_t j0 = 0, j1 = 1;
	size_t j ;
	std::vector<size_t> ind;
	if (size == 0)
		return ind;
	ind.push_back(j0);
	ind.push_back(j1);
	while (true)
	{
		// j(n) = j(n-1) + 2 * j(n-2)
		j = j0 + 2 * j1;
		if (j >= size)
			break;
		ind.push_back(j);
		j0 = j1;
		j1 = j;
	}
	// std::cout << "Jacobsthal indices generated: ";
	// for (size_t i = 0; i < ind.size(); ++i)
	// 	std::cout << ind[i] << " ";
	// std::cout << std::endl;
	// 6 7 4 2
	// 6 2
	// 2
	return ind;
}

void PmergeMe::SplitNumbers(std::vector<std::pair<int, int> >& pairs, std::vector<int> &winner, std::vector<int> &loser)
{
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		winner.push_back(it->first);
		loser.push_back(it->second);
	}
}
void PmergeMe::sort_fn_deq()
{
	clock_t start = clock();
	//
	std::deque<int> ls = deque_sort(this->deq);
	//
	clock_t end = clock();
	double time_us = (end - start) * 1e6 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->vec.size() 
	<< " elements with std::deque : " << time_us << "us" << std::endl;
    std::cout << "Deque: ";
    for (size_t i = 0; i < ls.size(); ++i)
        std::cout << ls[i] << " ";
    std::cout << std::endl;
}

std::deque<int> PmergeMe::deque_sort(std::deque<int> deque)
{
	std::deque<int> winner, losers;
	std::deque<std::pair<int, int> > pairs;
	int odd;
	odd = -1;
	if (deque.size() == 1)
		return deque;
	fillPairDeque(pairs, odd, deque);
	SplitNumbersDeque(pairs, winner, losers);
	winner = deque_sort(winner);
	addToWinnersDeque(winner, losers, odd);
	return winner;	
}

void PmergeMe::fillPairDeque(std::deque<std::pair<int, int> >& pairs, int& odd, std::deque<int> deque)
{
	size_t size = deque.size();
	if (size % 2 != 0)
	{
		odd = deque[size - 1];
		size -= 1;
	}
	else
	{
		odd = -1;
	}

	for (size_t i = 0; i < size; i += 2)
	{

		if (deque[i] < deque[i+1])
		{
			std::pair<int, int> pr(deque[i+1], deque[i]);
			pairs.push_back(pr);
		}
		else{
			std::pair<int, int> pr(deque[i], deque[i + 1]);
			pairs.push_back(pr);
		}
	}
}

void PmergeMe::SplitNumbersDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& winner, std::deque<int>& loser)
{
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		winner.push_back(it->first);
		loser.push_back(it->second);
	}
}

void PmergeMe::addToWinnersDeque(std::deque<int>& winner, const std::deque<int>& losers, int odd)
{
	// std::cout << "*****" ;
	std::deque<size_t> insertOrder = getJacobsthalIndicesDeque(losers.size());
	// for (size_t i = 0; i < insertOrder.size(); i++)
	// {
	// 	std::cout << insertOrder[i];
	// }
	// std::cout << "****" << std::endl;
    for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		size_t index = insertOrder[i];
        if (index < losers.size())
            binaryInsertDeque(winner, losers[index]);
	}
	std::vector<size_t> insertedIndices(insertOrder.begin(), insertOrder.end());
    for (size_t i = 0; i < losers.size(); ++i)
    {
        if (std::find(insertedIndices.begin(), insertedIndices.end(), i) == insertedIndices.end())
            binaryInsertDeque(winner, losers[i]);
    }
    if (odd != -1)
        binaryInsertDeque(winner, odd);
}

std::deque<size_t> PmergeMe::getJacobsthalIndicesDeque(size_t size)
{
	size_t j0 = 0, j1 = 1;
	size_t j ;
	std::deque<size_t> ind;
	if (size == 0)
		return ind;
	ind.push_back(j0);
	ind.push_back(j1);
	while (true)
	{
		// j(n) = j(n-1) + 2 * j(n-2)
		j = j0 + 2 * j1;
		if (j >= size)
			break;
		ind.push_back(j);
		j0 = j1;
		j1 = j;
	}
	// std::cout << "Jacobsthal indices generated: ";
	// for (size_t i = 0; i < ind.size(); ++i)
	// 	std::cout << ind[i] << " ";
	// std::cout << std::endl;
	// 6 7 4 2
	// 6 2
	// 2
	return ind;
}
void PmergeMe::binaryInsertDeque(std::deque<int>& cont, int value)
{
    std::deque<int>::iterator pos = std::lower_bound(cont.begin(), cont.end(), value);
    cont.insert(pos, value);
}

PmergeMe::~PmergeMe(){}