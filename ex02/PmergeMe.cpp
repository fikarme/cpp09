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
	if (k < 0)
		return 0;
	return ((1 << (k + 1)) + (k % 2 == 0 ? 1 : -1)) / 3;
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

void PmergeMe::processVecPairs(vector<int> &nums, vector<int> &mainChain, vector<int> &pend) {
	vector<pair<int, int> > pairs;
	for (size_t i = 0; i < nums.size(); i += 2)
		if (nums[i] > nums[i+1])
			pairs.push_back(make_pair(nums[i], nums[i+1]));
		else
			pairs.push_back(make_pair(nums[i+1], nums[i]));

	for (size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
}

void PmergeMe::sortVec(vector<int> nums) {
	// Base case: a list of 0 or 1 is already sorted
	if (nums.size() < 2) {
		_vecSorted = nums;
		return;
	}

	// Handle the straggler if the list size is odd
	int straggler = -1;
	bool hasStraggler = nums.size() % 2 != 0;
	if (hasStraggler) {
		straggler = nums.back();
		nums.pop_back();
	}

	// Create and sort pairs, then split into main and pend chains
	vector<int> mainChain, pend;
	processVecPairs(nums, mainChain, pend);

	// Recursively sort the main chain of larger elements
	sortVec(mainChain);
	vector<int> sortedChain = _vecSorted; // Get the result from the member variable

	// Insert the pending elements into the sorted main chain using binary search
	for (size_t i = 0; i < pend.size(); ++i) {
		vector<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), pend[i]);
		sortedChain.insert(it, pend[i]);
	}

	// Insert the straggler if it exists
	if (hasStraggler) {
		vector<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), straggler);
		sortedChain.insert(it, straggler);
	}

	// The final sorted list is now ready
	_vecSorted = sortedChain;
}
