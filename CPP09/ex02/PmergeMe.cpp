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
	// std::cout << "where" << std::endl;
	// // std::cout << nb[0] << std::endl;
	// std::cout << "where" << std::endl;
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
	vec_sort(this->vec);
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


// std::vector<int>    Vector::fordJohnsonSort(std::vector<int> numbers){
//     std::vector<int> winners, losers;
//     std::vector<std::pair<int, int> > pairsVector;
//     int odd = -1;

//     if (numbers.size() == 1)
//         return (numbers);
//     pairsVector = makeSortedPairs(numbers, odd);
//     separatePairs(pairsVector, winners, losers);
//     winners = fordJohnsonSort(winners);
//     insertIntoWinners(winners, losers, odd);
//     return (winners);
// }

std::vector<int> PmergeMe::vec_sort(std::vector<int> vect)
{
	
	std::vector<int> winner, losers;
	std::vector<std::pair<int, int> > pairs;
	int odd;
	odd = -1;
	if (vect.size() == 1)
		return vect;
	fillPair(pairs, odd, vect);
	// std::cout << "odd value: " << odd << std::endl;
	SplitNumbers(pairs, winner, losers);
	// for (std::vector<int>::iterator it = winner.begin(); it != winner.end(); it++)
	// {
	// 	std::cout << " " << *it << ",";
	// }
	// std::cout << std::endl;
	// for (std::vector<int>::iterator it = losers.begin(); it != losers.end(); it++)
	// {
	// 	std::cout << "Lossers: " << *it << std::endl;
	// }
	return winner;
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
	// std::cout << "before: ";
    // for (size_t i = 0; i < this->vec.size(); ++i)
    //     std::cout << this->vec[i] << " ";
    // std::cout << std::endl;
	clock_t start = clock();
	//
	clock_t end = clock();
	double time_us = (end - start) * 1e6 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->vec.size() 
	<< " elements with std::deque : " << time_us << "us" << std::endl;
    // std::cout << "Deque: ";
    // for (size_t i = 0; i < this->deq.size(); ++i)
    //     std::cout << this->deq[i] << " ";
    // std::cout << std::endl;
}


PmergeMe::~PmergeMe(){}