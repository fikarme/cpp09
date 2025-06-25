#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
	}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_database = other._database;
		}
	return *this;
	}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10)
		return false;

	try {
		int year = atoi(date.substr(0, 4).c_str());
		int month = atoi(date.substr(5, 2).c_str());
		int day = atoi(date.substr(8, 2).c_str());

		if (year < 2009)
			return false;
		if (month < 1 || month > 12)
			return false;
		if (day < 1 || day > 31)
			return false;

		if (month == 2) {
			bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
			if (isLeapYear && day > 29)
				return false;
			if (!isLeapYear && day > 28)
				return false;
			}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return false;

		return true;
		}
	catch (std::exception &e) {
		return false;
		}
	}

bool BitcoinExchange::read_database() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		return false;
		}

	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		size_t comma = line.find(',');
		if (comma != std::string::npos) {
			std::string date = line.substr(0, comma);
			float value = atof(line.substr(comma + 1).c_str());
			_database[date] = value;
			}
		}
	return true;
	}

bool isNumber(const std::string &s) {
	bool decimalPointSeen = false;
	size_t i = 0;
	while (i < s.length() && isspace(s[i])) i++;
	if (i < s.length() && (s[i] == '-' || s[i] == '+')) i++;
	bool digitSeen = false;
	for (; i < s.length(); ++i) {
		if (isdigit(s[i])) {
			digitSeen = true;
			continue;
			}
		if (s[i] == '.') {
			if (decimalPointSeen) return false;
			decimalPointSeen = true;
			continue;
			}
		if (isspace(s[i])) break;
		return false;
		}
	while (i < s.length() && isspace(s[i])) i++;
	return digitSeen && i == s.length();
	}

void BitcoinExchange::process_input(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
		}

	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		size_t separator = line.find(" | ");
		if (separator == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
			}

		std::string date = line.substr(0, separator);
		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
			}

		try {
			std::string valueStr = line.substr(separator + 3);
			if (!isNumber(valueStr)) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
				}
			float value = atof(valueStr.c_str());
			if (value < 0) {
				std::cout << "Error: not a positive number." << std::endl;
				continue;
				}
			if (value > 1000) {
				std::cout << "Error: too large a number." << std::endl;
				continue;
				}

			std::map<std::string, float>::iterator it = _database.lower_bound(date);
			if (it == _database.begin() && it->first != date) {
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
				}
			if (it == _database.end() || it->first != date)
				--it;

			std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
			}
		catch (std::exception &e) {
			std::cout << "Error: bad input => " << line << std::endl;
			}
		}
	}
