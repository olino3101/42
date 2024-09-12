#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <limits>
// le container cest le fichier stocker
class BitcoinEx
{
    public:
    BitcoinEx(const char *argv);
    BitcoinEx(const BitcoinEx & other);
    BitcoinEx& operator=(const BitcoinEx & other);
    std::ifstream&  getFile();

    long double stold(std::string str);
    long double getValue(const std::string& targetDate);
    bool checkLine(std::string line);

    void initData();

    private:

    bool open_file(const char *argv);
    std::ifstream file;
    std::map<std::string, long double> data;
    BitcoinEx();
};

#endif