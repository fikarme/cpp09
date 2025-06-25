#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	if (!btc.read_database())
	{
		std::cout << "Error: could not open database file." << std::endl;
		return 1;
	}
	btc.process_input(argv[1]);

	return 0;
}
