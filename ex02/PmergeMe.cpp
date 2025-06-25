#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpy) {
	*this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_vec = rhs._vec;
		_deq = rhs._deq;
		_timeVec = rhs._timeVec;
		_timeDeq = rhs._timeDeq;
	}
	return *this;
}

size_t PmergeMe::jacobsthal(int k) {
	return (pow(2, k + 1) + pow(-1, k)) / 3;
}

void PmergeMe::addArgs(int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		int num = atoi(av[i]);
		_vec.push_back(num);
		_deq.push_back(num);
	}
}

void PmergeMe::sort() {
	clock_t vecStart = clock();
	sortVec(_vec);
	clock_t vecEnd = clock();
	_timeVec = (vecEnd - vecStart) * 1000.0 / CLOCKS_PER_SEC;

	clock_t deqStart = clock();
	// _deqSorted = sortDeq(_deq);
	clock_t deqEnd = clock();
	_timeDeq = (deqEnd - deqStart) * 1000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::sortVecPair(vector<int> nums) {
	vector<int>::iterator it = nums.begin();
	vector<int>::iterator next = it + 1;
	if (*it > *next)
		swap(*it, *next);
	_vecSorted = nums;
}

void PmergeMe::sortVec(vector<int> nums) {
	if (nums.size() == 2) {
		sortVecPair(nums);
		return;
	}
	
	size_t k = 0;
	while (jacobsthal(k) < nums.size()) {
		++k;
	}
	
	vector<int> sorted;
	for (size_t i = 0; i < k; ++i) {
		sorted.push_back(jacobsthal(i));
	}
	
}

void PmergeMe::processVecPairs(vector<int> &nums, vector<int> &bigger, vector<int> &smaller) {
	for (size_t i = 0; i < nums.size(); ++i) {
		if (i % 2 == 0) {
			bigger.push_back(nums[i]);
		} else {
			smaller.push_back(nums[i]);
		}
	}
}
