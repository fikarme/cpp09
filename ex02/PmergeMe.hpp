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

class PmergeMe {
public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &rhs);
	
	double _timeVec;
	double _timeDeq;
	vector<int> _vec;
	vector<int> _vecSorted;
	deque<int> _deq;
	deque<int> _deqSorted;

	static size_t jacobsthal(int k);
	void addArgs(int ac, char **av);
	void sortBuble();
	void sortClock();
	
	static vector<int> sortVecPair(vector<int> nums);
	static void processVecPairs(vector<int> &nums, vector<int> &bigger, vector<int> &smaller);
	static vector<int> sortVec(vector<int> nums);
	
		
	// static deque<int> sortDeqPair(deque<int> nums);
	// static void processDeqPairs(deque<int> &nums, deque<int> &bigger, deque<int> &smaller);
	// static deque<int> sortDeq(deque<int> nums);
	
	
private:
};

#endif
