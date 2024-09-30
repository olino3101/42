#include "BitcoinExchange.hpp"

    static int printErr(std::string str)
    {
        std::cout << str << std::endl;
        return 1;
    }

    long double BitcoinEx::stold(std::string str) {
        long double value;
        std::stringstream ss(str);
        ss >> value;
        if(ss.fail())
            return -1;
        return value;
    }
        
    long double BitcoinEx::getValue(const std::string& targetDate) {
        std::map<std::string, long double>::const_iterator it = data.lower_bound(targetDate);
        if (it == data.begin()) {
            return it->second;
        }
        if (it == data.end()) {
            return (--it)->second;
        }
        std::map<std::string, long double>::const_iterator prevIt = it;
        --prevIt;
        if (targetDate.compare(it->first) == targetDate.compare(prevIt->first))
            return it->second;
        return prevIt->second;
    }

    bool BitcoinEx::checkLine(std::string line) {
        size_t pos = line.find('-');
        if (pos == std::string::npos && printErr("Error: bad input"))
            return false;

        std::string year_str = line.substr(0, pos);
        double year = stold(year_str);
        if ((year <= 2000 || year >= 2025) && printErr("Error: bad input"))
            return false;

        size_t i = pos + 1;
        pos = line.find('-', i);
        if (pos == std::string::npos && printErr("Error: bad input"))
            return false;

        std::string month_str = line.substr(i, pos - i);
        double month = stold(month_str);
        if ((month < 0 || month > 12 || month_str.length() != 2) && printErr("Error: bad input")) 
            return false;

        i = pos + 1;
        pos = line.find('|', i);
        if (pos == std::string::npos && printErr("Error: bad input"))
            return false;


        std::string day_str = line.substr(i, pos - i - 1);
        double day = stold(day_str);
        if ((day < 0 || day > 31 || day_str.length() != 2) && printErr("Error: bad input"))
            return false;

        std::string value_str = line.substr(pos + 1);
        double value = stold(value_str);
        if (value < 0 && printErr("Error: not a positive number"))
            return false;

        if (value > std::numeric_limits<int>::max() && printErr("Error: too large a number"))
            return false;
        return true;
    }

    void BitcoinEx::initData() {
        std::ifstream   dataF("data.csv");
        std::string line;
        long double value;

        while(std::getline(dataF, line))
        {
            size_t pos = line.find(',');
            std::stringstream ss(line.substr(pos + 1));
            ss >> value;
            data[line.substr(0, pos)] = value;
        }
    }

    bool BitcoinEx::open_file(const char *argv) {
        file.open(argv);

        if (!file.is_open()) {
            std::cout << "wrong file" << std::endl;
            return false;
        }
        return true;
    }
     std::ifstream& BitcoinEx::getFile() {
        return this->file;
     }

    BitcoinEx::BitcoinEx(const char *argv) 
    {
        open_file(argv);
        initData();
    }
    BitcoinEx::BitcoinEx(const BitcoinEx & other) {
        data = other.data;
    }
    BitcoinEx& BitcoinEx::operator=(const BitcoinEx & other) {
        if (this != &other)
        {
            data = other.data;
        }
        return *this;
    }
    BitcoinEx::BitcoinEx() {}