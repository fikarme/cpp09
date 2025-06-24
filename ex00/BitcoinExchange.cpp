#include "BitcoinExchange.hpp"

void r(const string &msg) {
	cerr << "\033[1;31mERROR: " << msg << "\033[0m" << endl;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	*this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs)
		this->_db = rhs._db;
	return *this;
}

BitcoinExchange::BitcoinExchange() {
	ifstream file("data.csv");
	string line;

	if (!file.is_open())
		throw runtime_error("could not open data.csv.");

	getline(file, line);
	while (getline(file, line)) {
		size_t commaPos = line.find(',');
		if (commaPos != string::npos) {
			string date = line.substr(0, commaPos);
			float rate = atof(line.substr(commaPos + 1).c_str());
			_db[date] = rate;
		}
	}
}

void BitcoinExchange::run(const string &inputFile) {
	ifstream file(inputFile.c_str());
	string line;

	if (!file.is_open()) {
		r("could not open file.");
		return;
	}

	getline(file, line); // skip header
	while (getline(file, line))
		processLine(line);
}

void BitcoinExchange::processLine(const string &line) {
	size_t pipePos = line.find(" | ");
	if (pipePos == string::npos) {
		r("PIPE bad input => " + line);
		return;
	}

	string date = line.substr(0, pipePos);
	string valStr = line.substr(pipePos + 3);
	float val;

	if (date.empty() || valStr.empty()) {
		r("EMPTY bad input => " + line);
		return;
	}
	if (!isValidDate(date)) {
		r("DATE bad input => " + date);
		return;
	}
	if (!isValidVal(valStr, val))
		return;

	map<string, float>::iterator it = _db.lower_bound(date);
	if (it == _db.end() || it->first != date) {
		if (it == _db.begin()) {
			r("no data for or before this date.");
			return;
		}
		--it; // to get the closest lower date
	}

	cout << date << " => " << val << " = " << val * it->second << endl;
}

bool BitcoinExchange::isValidDate(const string &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year	= atoi(date.substr(0, 4).c_str());
	int month	= atoi(date.substr(5, 2).c_str());
	int day		= atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	if (month == 2 && day > 29)
		return false;
	if (month == 2 && day == 29 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		return false;
	return true;
}

bool BitcoinExchange::isValidVal(const string &valStr, float &val) {
	char *end;
	val = strtof(valStr.c_str(), &end);
	
	if (val < 0) {
		r("not a positive number.");
		return false;
	}
	if (val > 1000) {
		r("too large a number.");
		return false;
	}
	if (valStr.find_first_not_of("+-0123456789.") != string::npos) {
		r("NAN bad input => " + valStr);
		return false;
	}
	if (end == valStr.c_str() || *end != '\0') {
		r("NAN bad input => " + valStr);
		return false;
	}
	return true;
}
