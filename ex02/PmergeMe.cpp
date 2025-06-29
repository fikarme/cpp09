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
	cout << "Before:	";
	for (int i = 1; i < ac; ++i)
		cout << av[i] << " ";
	cout << endl;

	cout << "VEC After: ";
	for (int i = 0; i < ac - 1; ++i)
		cout << _vecSorted[i] << " ";
	cout << endl;

	// cout << "DEQ After: ";
	// for (int i = 0; i < ac - 1; ++i)
	// 	cout << _deqSorted[i] << " ";
	// cout << endl;

	// cout << fixed << setprecision(7)
	// << "Time to process a range of " << ac - 1
	// << " elements with std::vector: "<< _timeVec
	// << " seconds" << endl

	// << "Time to process a range of " << ac - 1
	// << " elements with std::deque:  "<< _timeDeq
	// << " seconds" << endl

	// << "Time difference: "
	// << (_timeVec - _timeDeq)
	// << " seconds" << endl

	// << "The faster one:  "
	// << (_timeVec < _timeDeq ? "std::vector" : "std::deque")
	// << endl << endl;
}	//!!!	subject çıktısına göre düzenle

inline size_t PmergeMe::jacobsthal(int k) {
	size_t prev = 0; // J(0)
	size_t curr = 1; // J(1)
	size_t next;
	int i = 2;

	while (i <= k)
	{
		next = curr + 2 * prev;
		prev = curr;
		curr = next;
		++i;
	}
	return curr;
	//return ((1 << (k + 1)) + (k % 2 == 0 ? 1 : -1)) / 3; ASIL DORU
	// return ((1 << (k)) - (k % 2 == 0 ? 1 : -1)) / 3;
}	//	J(k) = (2^(k+1) + (-1)^k) / 3

void PmergeMe::sort(int ac, char **av) {
	clock_t vecStart = clock();
	for (int i = 1; i < ac; ++i)
		_vec.push_back(atoi(av[i]));
	sortVec(_vec);
	clock_t vecEnd = clock();
	_timeVec = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC;

	clock_t deqStart = clock();
	for (int i = 1; i < ac; ++i)
		_deq.push_back(atoi(av[i]));
	sortDeq(_deq);
	clock_t deqEnd = clock();
	_timeDeq = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC;

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

	vector<size_t> jacobIndices;
	//jacobIndices is a list of indices into pend that tells us
	//the optimal order to insert them,
	//based on the Jacobsthal sequence,
	size_t lastJacob = 1;
	int k = 2;
	while (true) {
		size_t jacob = jacobsthal(k);
		cout <<  "k: " << k << " jacob: " << jacob << endl;
		if (jacob > pend.size())
			jacob = pend.size();
		for (size_t i = jacob; i > lastJacob; --i)
			jacobIndices.push_back(i - 1);
		if (jacob == pend.size())
			break;
		lastJacob = jacob;
		++k;
	}

	for (size_t i = 0; i < jacobIndices.size(); ++i) {
		int val = pend[jacobIndices[i]];
		vector<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), val);
		sortedChain.insert(it, val);
	}	//	lowerbound önemi

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

	deque<size_t> jacobIndices;
	size_t lastJacob = 1;
	int k = 2;
	while (true) {
		size_t jacob = jacobsthal(k);
		if (jacob > pend.size())
			jacob = pend.size();
		for (size_t i = jacob; i > lastJacob; --i)
			jacobIndices.push_back(i - 1);
		if (jacob == pend.size())
			break;
		lastJacob = jacob;
		++k;
	}

	for (size_t i = 0; i < jacobIndices.size(); ++i) {
		int val = pend[jacobIndices[i]];
		deque<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), val);
		sortedChain.insert(it, val);
	}

	if (hasStraggler) {
		deque<int>::iterator it = lower_bound(sortedChain.begin(), sortedChain.end(), straggler);
		sortedChain.insert(it, straggler);
	}

	_deqSorted = sortedChain;
}
