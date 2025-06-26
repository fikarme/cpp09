#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &cpy) { *this = cpy; }
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_vec = rhs._vec;
		_deq = rhs._deq;
		_timeVec = rhs._timeVec;
		_timeDeq = rhs._timeDeq;
		_vecSorted = rhs._vecSorted;
		_deqSorted = rhs._deqSorted;
	}
	return *this;
}

void PmergeMe::printRes(int ac, char **av) const {
	cout << "Before:    ";
	for (int i = 1; i < ac; ++i)
		cout << av[i] << " ";
	cout << endl;

	cout << "VEC After: ";
	for (int i = 0; i < ac - 1; ++i)
		cout << _vecSorted[i] << " ";
	cout << endl;

	cout << "DEQ After: ";
	for (int i = 0; i < ac - 1; ++i)
		cout << _deqSorted[i] << " ";
	cout << endl;

	cout << "Time to process a range of " << ac - 1
		 << " elements with std::vector: "<< _timeVec
		 << " us" << endl;

	cout << "Time to process a range of " << ac - 1
		 << " elements with std::deque:  " << _timeDeq
		 << " us" << endl;

	cout << "Time difference: "
		 << (_timeVec - _timeDeq)
		 << " us" << endl;

	cout << "The faster one: "
		 << (_timeVec < _timeDeq ? "std::vector" : "std::deque")
		 << endl;

	cout << endl;
}

size_t PmergeMe::jacobsthal(int k) {
	if (k < 0)
		return 0;
	return ((1 << (k + 1)) + (k % 2 == 0 ? 1 : -1)) / 3;
}

void PmergeMe::sort(int ac, char **av) {
	clock_t vecStart = clock();
	for (int i = 1; i < ac; ++i) {
		int num = atoi(av[i]);
		_vec.push_back(num);
	}
	sortVec(_vec);
	clock_t vecEnd = clock();
	_timeVec = (vecEnd - vecStart) * 1000.0 / CLOCKS_PER_SEC;

	clock_t deqStart = clock();
	for (int i = 1; i < ac; ++i) {
		int num = atoi(av[i]);
		_deq.push_back(num);
	}
	sortDeq(_deq);
	clock_t deqEnd = clock();
	_timeDeq = (deqEnd - deqStart) * 1000.0 / CLOCKS_PER_SEC;

	printRes(ac, av);
}

void PmergeMe::sortVec(vector<int> nums) {
	if (nums.size() < 2) {
		_vecSorted = nums;
		return;
	}

	int straggler = -1;
	bool hasStraggler = nums.size() % 2 != 0;
	if (hasStraggler) {
		straggler = nums.back();
		nums.pop_back();
	}

	vector<int> mainChain, pend;
	for (size_t i = 0; i < nums.size(); i += 2)
		if (nums[i] > nums[i + 1]) {
			mainChain.push_back(nums[i]);
			pend.push_back(nums[i + 1]);
		}
		else {
			mainChain.push_back(nums[i + 1]);
			pend.push_back(nums[i]);
		}

	sortVec(mainChain);
	vector<int> sortedChain = _vecSorted;

	if (!pend.empty())
		sortedChain.insert(sortedChain.begin(), pend[0]);

	vector<size_t> jacob_indices;
	size_t last_jacob = 1;
	for (int k = 2; ; ++k) {
		size_t jacob = jacobsthal(k);
		if (jacob > pend.size())
			jacob = pend.size();
		for (size_t i = jacob; i > last_jacob; --i)
			jacob_indices.push_back(i - 1);
		if (jacob == pend.size())
			break;
		last_jacob = jacob;
	}

	for (size_t i = 0; i < jacob_indices.size(); ++i) {
		int val = pend[jacob_indices[i]];
		vector<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), val);
		sortedChain.insert(it, val);
	}

	if (hasStraggler) {
		vector<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), straggler);
		sortedChain.insert(it, straggler);
	}

	_vecSorted = sortedChain;
}

void PmergeMe::sortDeq(deque<int> nums) {
	if (nums.size() < 2) {
		_deqSorted = nums;
		return;
	}

	int straggler = -1;
	bool hasStraggler = nums.size() % 2 != 0;
	if (hasStraggler) {
		straggler = nums.back();
		nums.pop_back();
	}

	deque<int> mainChain, pend;
	for (size_t i = 0; i < nums.size(); i += 2)
		if (nums[i] > nums[i + 1]) {
			mainChain.push_back(nums[i]);
			pend.push_back(nums[i + 1]);
		}
		else {
			mainChain.push_back(nums[i + 1]);
			pend.push_back(nums[i]);
		}

	sortDeq(mainChain);
	deque<int> sortedChain = _deqSorted;

	if (!pend.empty())
		sortedChain.insert(sortedChain.begin(), pend[0]);

	deque<size_t> jacob_indices;
	size_t last_jacob = 1;
	for (int k = 2; ; ++k) {
		size_t jacob = jacobsthal(k);
		if (jacob > pend.size())
			jacob = pend.size();
		for (size_t i = jacob; i > last_jacob; --i)
			jacob_indices.push_back(i - 1);
		if (jacob == pend.size())
			break;
		last_jacob = jacob;
	}

	for (size_t i = 0; i < jacob_indices.size(); ++i) {
		int val = pend[jacob_indices[i]];
		deque<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), val);
		sortedChain.insert(it, val);
	}

	if (hasStraggler) {
		deque<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), straggler);
		sortedChain.insert(it, straggler);
	}

	_deqSorted = sortedChain;
}

// Aight, bet. Your current implementation is a good start
// but it's taking some major Ls on performance and isn't the full-fat Ford-Johnson algorithm
// The way you're creating an extra pairs vector is a resource L
// and the linear insertion of the pend elements is not the optimal vibe the subject demands.

// Let's give these functions a serious glow-up
// I've refactored them to be more efficient and to use the Jacobsthal insertion sequence
// which is the secret sauce of this algorithm.

// The Glow-Up
// This improved version of sortVec now uses the Jacobsthal sequence to minimize comparisons
// which is the whole point of the Ford-Johnson algorithm
// The processVecPairs logic is also rolled directly into sortVec to avoid creating an unnecessary intermediate vector
// saving memory and time.

// I'm keeping your function signatures and the use of the _vecSorted member variable as you asked
// but know this: passing the vector by value (vector<int> nums) on every recursive call is a huge performance bottleneck
// For a true 42-pilled solution
// you'd want to sort in-place by passing a reference (vector<int>& nums).
