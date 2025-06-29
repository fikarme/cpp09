
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <stdexcept>
using std::runtime_error;
#include <stdlib.h>
using std::atoi;
#include <ctime>
using std::clock;
using std::clock_t;
#include <algorithm>
using std::lower_bound;
#include <iomanip>
using std::setprecision;
using std::fixed;

class PmergeMe {
private:
	double		_timeVec;
	double		_timeDeq;
	vector<int> _vec;
	vector<int> _vecSorted;
	deque<int> 	_deq;
	deque<int>	_deqSorted;

	inline size_t jacobsthal(int k);
	void sortVec(vector<int> nums);
	void sortDeq(deque<int> nums);
	void printRes(int ac, char **av) const;

public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &rhs);

	void sort(int ac, char **av);
};

#endif
