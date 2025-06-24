#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		r("could not open file.");
		return 1;
	}
	
	try
	{
		BitcoinExchange btc;
		btc.run(av[1]);
	}
	catch (const exception &e) { r(e.what());}
	catch (...) { r("an unknown error occurred.");}

	return 0;
}
