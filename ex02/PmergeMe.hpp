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

class PmergeMe {
public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &rhs);

private:
	vector<int> _vec;
	deque<int> _deq;
};

#endif
