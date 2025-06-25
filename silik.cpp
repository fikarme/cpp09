// size_t PmergeMe::jacobsthal(int k) {
// 	return (pow(2, k + 1) + pow(-1, k)) / 3;
// }

// size_t PmergeMe::jacobsthal(int k) {
//	 if (k < 0)
// 		return 0;
//	 return (static_cast<size_t>(pow(2, k + 1)) + (k % 2 == 0 ? 1 : -1)) / 3;
// }

// size_t PmergeMe::jacobsthal(int k) {
//	 if (k < 0)
//		 return 0;
//	 return ((1 << (k + 1)) + (k % 2 == 0 ? 1 : -1)) / 3;
// }

// void PmergeMe::sortVecPair(vector<int> nums) {
// 	vector<int>::iterator it = nums.begin();
// 	vector<int>::iterator next = it + 1;
// 	if (*it > *next)
// 		swap(*it, *next);
// 	_vecSorted = nums;
// }

// void PmergeMe::sortBuble() {
// 	clock_t vecStart = clock();
// 	for (size_t i = 0; i < _vec.size() - 1; ++i) {
// 		for (size_t j = i + 1; j < _vec.size(); ++j) {
// 			if (_vec[i] > _vec[j]) {
// 				std::swap(_vec[i], _vec[j]);
// 			}
// 		}
// 	}
// 	clock_t vecEnd = clock();
// 	_timeVec = (vecEnd - vecStart) * 1000.0 / CLOCKS_PER_SEC;

// 	clock_t deqStart = clock();
// 	for (size_t i = 0; i < _deq.size() - 1; ++i) {
// 		for (size_t j = i + 1; j < _deq.size(); ++j) {
// 			if (_deq[i] > _deq[j]) {
// 				std::swap(_deq[i], _deq[j]);
// 			}
// 		}
// 	}
// 	clock_t deqEnd = clock();
// 	_timeDeq = (deqEnd - deqStart) * 1000.0 / CLOCKS_PER_SEC;
// }

// void PmergeMe::sortVec(vector<int> nums) {
// 	if (nums.size() == 2) {
// 		sortVecPair(nums);
// 		return;
// 	}

// 	size_t k = 0;
// 	while (jacobsthal(k) < nums.size()) {
// 		++k;
// 	}

// 	vector<int> sorted;
// 	for (size_t i = 0; i < k; ++i) {
// 		sorted.push_back(jacobsthal(i));
// 	}

// }

// void PmergeMe::processVecPairs(vector<int> &nums, vector<int> &bigger, vector<int> &smaller) {
// 	for (size_t i = 0; i < nums.size(); ++i) {
// 		if (i % 2 == 0) {
// 			bigger.push_back(nums[i]);
// 		} else {
// 			smaller.push_back(nums[i]);
// 		}
// 	}
// }
