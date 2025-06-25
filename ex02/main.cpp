#include "PmergeMe.hpp"

bool r(const string &msg) {
	cerr << "\033[1;31mERROR: " << msg << "\033[0m" << endl;
	return false;
}

bool isValidArg(int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		string arg = av[i];
		if (arg.empty())
			return false;
		for (size_t j = 0; j < arg.length(); ++j)
			if (!isdigit(arg[j]))
				return false;
	}
	return true;
}

bool isSorted(int ac, char **av) {
	for (int i = 1; i < ac - 1; ++i)
		if (atoi(av[i]) > atoi(av[i + 1]))
			return false;
	return true;
}

bool isDuplicated(int ac, char **av) {
	for (int i = 1; i < ac - 1; ++i) {
		for (int j = i + 1; j < ac; ++j) {
			if (atoi(av[i]) == atoi(av[j]))
				return true;
		}
	}
	return false;
}

bool isNegative(int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		if (atol(av[i]) < 0)
			return true;
	}
	return false;
}

int main(int ac, char **av) {

	if (ac < 3)
		return r("positive integer sequence as an arg req");
	
	if (ac > 3001)
		return r("too many arg");

	if (!isValidArg(ac, av))
		return r("invalid arg");

	if (isNegative(ac, av))
		return r("negative arg");

	if (isSorted(ac, av))
		return r("already sorted");
	
	if (isDuplicated(ac, av))
		return r("duplicated arg");
		
	PmergeMe PmergeMe;
	try
	{
		PmergeMe.addArgs(ac, av);
		PmergeMe.sort();
	}
	catch (const std::runtime_error &e) { return r(e.what()); }
	
	cout << "Before: ";
	for (int i = 1; i < ac; ++i)
		cout << av[i] << " ";
	cout << endl;
	
	cout << "VEC After: ";
	for (int i = 0; i < ac - 1; ++i)
		cout << PmergeMe._vecSorted[i] << " ";
	cout << endl;
	
	cout << "DEQ After: ";
	for (int i = 0; i < ac - 1; ++i)
		cout << PmergeMe._deqSorted[i] << " ";
	cout << endl;
	
	cout << "Time to process a range of " << ac - 1
		 << " elements with std::vector: "<< PmergeMe._timeVec
		 << " us" << endl;
		 
	cout << "Time to process a range of " << ac - 1
		 << " elements with std::deque: " << PmergeMe._timeDeq
		 << " us" << endl;

	// cout << "Time difference: "
	// 	 << fabs(PmergeMe._timeVec - PmergeMe._timeDeq)
	// 	 << " us" << endl;
		 
	// cout << "Ratio: "
	// 	 << (PmergeMe._timeVec / PmergeMe._timeDeq)
	// 	 << endl;
		 
	// cout << "Jacobsthal: "
	// 	 << PmergeMe.jacobsthal(13) // Example usage, can be adjusted
	// 	 << endl;
		 
	cout << endl;
	return 0;
}
