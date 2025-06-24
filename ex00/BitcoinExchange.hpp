#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;
using std::exception;
using std::runtime_error;

void r(const string &msg);

class BitcoinExchange {
private:
	map<string, float> _db;

	bool isValidDate(const string &date);
	bool isValidVal(const string &valStr, float &val);
	void processLine(const string &line);

public:
	~BitcoinExchange();
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void run(const string &inputFile);
};

#endif
