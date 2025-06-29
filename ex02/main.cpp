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
		if (arg.find_first_not_of("+0123456789") != string::npos)
			return false;
		if (atol(av[i]) > 2147483647)
			return false;
	}
	return true;
}

bool hasDuplicates(int ac, char **av) {
	for (int i = 1; i < ac; ++i)
		for (int j = i + 1; j < ac; ++j)
			if (atoi(av[i]) == atoi(av[j]))
				return true;
	return false;
}

int main(int ac, char **av) {
	if (ac < 3)
		return r("positive integer sequence as an arg req");

	if (ac > 3003)
		return r("too many arg");

	if (!isValidArg(ac, av))
		return r("invalid arg");

	if (hasDuplicates(ac, av))
		return r("duplicate arg");

	PmergeMe PmergeMe;
	PmergeMe.sort(ac, av);

	cout << "\n\033[1;31mMAIN ENDED\033[0m\n" << endl;

	return 0;
}
