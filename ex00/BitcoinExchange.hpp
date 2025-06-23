#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>

#define RST "\033[0m"
#define RED "\033[1;31m"
#define YLW "\033[1;33m"

using std::cout;
using std::endl;
using std::cerr;

class BitcoinExchange {
public:
	~BitcoinExchange();
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

private:
	
};

#endif
