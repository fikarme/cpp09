#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;
using std::exception;

inline void err(const string &msg);

class BitcoinExchange {
private:
	map<string, float> _db;

	BitcoinExchange();

	bool isValidDate(const string &date);
	bool isValidValue(const string &valueStr, float &value);
	void processLine(const string &line);

public:
	BitcoinExchange(const string &databaseFile);
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void run(const string &inputFile);
};

#endif
