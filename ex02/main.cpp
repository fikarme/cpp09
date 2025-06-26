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

	if (ac > 3003)
		return r("too many arg");

	if (!isValidArg(ac, av))
		return r("invalid arg");

	if (isNegative(ac, av))
		return r("negative arg");

	if (isDuplicated(ac, av))
		return r("duplicated arg");

	PmergeMe PmergeMe;
	PmergeMe.sort(ac, av);

	return 0;
}
