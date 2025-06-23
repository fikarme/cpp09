#include "BitcoinExchange.hpp"

inline void y(const char* msg) {
	cout << endl << YLW << " _/\\_____" << msg << "_____/\\_ " << RST << endl;
}

inline void r(const char *msg) { cerr << RED << msg << RST << endl; }

int main(int ac, char **av) {
	if (ac != 2) {
		cerr << RED << "Error: could not open file." << RST << endl;
		return 1;
	}





	return 0;
}
