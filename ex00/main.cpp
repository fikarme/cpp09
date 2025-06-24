#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		err("Error: could not open file.");
		return 1;
	}

	try
	{
		BitcoinExchange btc(av[1]);
		btc.run(av[1]);
	}
	catch (const exception &e) { err(e.what()); return 1; }
	catch (...) { err("An unknown error occurred."); return 1; }


	return 0;
}
