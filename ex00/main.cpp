#include "BitcoinExchange.hpp"

bool r(const string &msg) {
	cerr << "\033[1;31mERROR: " << msg << "\033[0m" << endl;
	return false;
}

int main(int ac, char **av) {
	if (ac != 2)
		return r("could not open file.");

	try
	{
		BitcoinExchange btc;
		btc.run(av[1]);
	}
	catch (const exception &e) { return r(e.what());}
	catch (...) { return r("an unknown error occurred.");}

	return 0;
}
