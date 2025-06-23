#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, float> _database;
        bool isValidDate(const std::string& date);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool read_database();
        void process_input(const std::string& filename);
};

#endif