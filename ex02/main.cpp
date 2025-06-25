#include "PmergeMe.hpp"

void r(const string &msg) {
	cerr << "\033[1;31mERROR: " << msg << "\033[0m" << endl;
}

int main(int ac, char **av) {
	if (ac != 2) {
		r("Error: Positive integer sequence as an argument required.");
		return 1;
	}





	return 0;
}
