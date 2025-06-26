
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
#include <cmath>
using std::pow;
#include <ctime>
using std::clock;
#include <algorithm>
using std::swap;
using std::lower_bound;

class PmergeMe {
private:
	double _timeVec;
	double _timeDeq;
	vector<int> _vec;
	vector<int> _vecSorted;
	deque<int> _deq;
	deque<int> _deqSorted;

	size_t jacobsthal(int k);
	void sort(int ac, char **av);
	void sortVec(vector<int> nums);
	void sortDeq(deque<int> nums);

public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &rhs);

};

#endif
