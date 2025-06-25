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

void PmergeMe::sortBuble() {
	clock_t vecStart = clock();
	for (size_t i = 0; i < _vec.size() - 1; ++i) {
		for (size_t j = i + 1; j < _vec.size(); ++j) {
			if (_vec[i] > _vec[j]) {
				std::swap(_vec[i], _vec[j]);
			}
		}
	}
	clock_t vecEnd = clock();
	_timeVec = (vecEnd - vecStart) * 1000.0 / CLOCKS_PER_SEC;

	clock_t deqStart = clock();
	for (size_t i = 0; i < _deq.size() - 1; ++i) {
		for (size_t j = i + 1; j < _deq.size(); ++j) {
			if (_deq[i] > _deq[j]) {
				std::swap(_deq[i], _deq[j]);
			}
		}
	}
	clock_t deqEnd = clock();
	_timeDeq = (deqEnd - deqStart) * 1000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::sortClock() {
	clock_t vecStart = clock();
	_vecSorted = sortVec(_vec);
	clock_t vecEnd = clock();
	_timeVec = (vecEnd - vecStart) * 1000.0 / CLOCKS_PER_SEC;

	clock_t deqStart = clock();
	// _deqSorted = sortDeq(_deq);
	clock_t deqEnd = clock();
	_timeDeq = (deqEnd - deqStart) * 1000.0 / CLOCKS_PER_SEC;
}

// vector<int> PmergeMe::sortVecPair(vector<int> nums) {
// 	vector<int> bigger, smaller;
// 	processVecPairs(nums, bigger, smaller);
// 	// return sortVec(bigger) + sortVec(smaller);
// }

vector<int> PmergeMe::sortVec(vector<int> nums) {
	if (nums.size() <= 1) {
		return nums;
	}
	
	size_t k = 0;
	while (jacobsthal(k) < nums.size()) {
		++k;
	}
	
	vector<int> sorted;
	for (size_t i = 0; i < k; ++i) {
		sorted.push_back(jacobsthal(i));
	}
	
	return sorted;
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
