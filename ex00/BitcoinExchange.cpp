#include "BitcoinExchange.hpp"

inline void err(const string &msg) {
	cerr << "\033[1;31m	ERROR: " << msg << "\033[0m" << endl;
}

BitcoinExchange::BitcoinExchange(const string &databaseFile) {
	ifstream file(databaseFile.c_str());
	string line;

	if (!file.is_open())
		throw runtime_error("could not open database file.");

	getline(file, line); // Skip header
	while (getline(file, line))
		{
		size_t commaPos = line.find(',');
		if (commaPos != string::npos)
			{
			string date = line.substr(0, commaPos);
			float rate = atof(line.substr(commaPos + 1).c_str());
			_db[date] = rate;
			}
		}
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

void BitcoinExchange::run(const string &inputFile) {
	ifstream file(inputFile.c_str());
	string line;

	if (!file.is_open())
		{
		err("could not open file.");
		return;
		}

	getline(file, line); // Skip header
	while (getline(file, line))
		processLine(line);
	}

void BitcoinExchange::processLine(const string &line) {
	size_t separatorPos = line.find(" | ");
	if (separatorPos == string::npos)
		{
		err("bad input => " + line);
		return;
		}

	string date = line.substr(0, separatorPos);
	string valueStr = line.substr(separatorPos + 3);
	float value;

	if (!isValidDate(date))
		{
		err("bad input => " + date);
		return;
		}
	if (!isValidValue(valueStr, value))
		return; // isValidValue prints its own errors

	// Find the exchange rate
	map<string, float>::iterator it = _db.lower_bound(date);
	if (it == _db.end() || it->first != date)
		{
		if (it == _db.begin())
			{
			err("no data for or before this date.");
			return;
			}
		--it; // Get the closest lower date
		}

	cout << date << " => " << value << " = " << value * it->second << endl;
	}

bool BitcoinExchange::isValidDate(const string &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	// This is a basic check; a full leap year check is extra credit
	return true;
	}

bool BitcoinExchange::isValidValue(const string &valueStr, float &value) {
	char *end;
	value = strtof(valueStr.c_str(), &end);

	if (*end != '\0' && *end != '\n') {
		// Check for trailing non-numeric characters, but allow empty space
		string temp = end;
		size_t first_char = temp.find_first_not_of(" \t\n\r");
		if (first_char != string::npos) {
			err("bad input => " + valueStr);
			return false;
			}
		}

	if (value < 0)
		{
		err("not a positive number.");
		return false;
		}
	if (value > 1000)
		{
		err("too large a number.");
		return false;
		}
	return true;
	}
