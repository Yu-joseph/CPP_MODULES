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
	vec_sort();
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

void PmergeMe::vec_sort()
{
	std::vector<int> mainChain;
	std::vector<int> pendingChain;
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