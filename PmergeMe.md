1.  `shuf -i 1-42 -n 31`
    *   `shuf`: The shuffle command. It randomizes lines of input.
    *   `-i 1-42`: This is the `--input-range` flag. It tells `shuf` to generate its own input: the numbers from 1 to 42.
    *   `-n 31`: This is the `--head-count` flag. It makes `shuf` output only the first 31 numbers from its randomized list.

2.  `| tr "\n" " "`
    *   `|`: The pipe. It sends the output from `shuf` (31 numbers, each on a new line) directly as input to the `tr` command.
    *   `tr "\n" " "`: The translate command. It finds every newline character (`\n`) and swaps it for a space (` `).


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
