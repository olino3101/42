#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "wrong number of arg" << std::endl;
        return 1;
    }
    BitcoinEx btc(argv[1]);
    if (!btc.getFile().is_open())
        return 1;
    std::string line;
    while (std::getline(btc.getFile(), line))
    {
        if (!btc.checkLine(line))
            continue;
        size_t pos = line.find(' ');
        long double btcValue = btc.getValue(line.substr(0, pos));
        size_t valPos = line.find('|');
        line.substr(pos + 1);
        double value = btc.stold(line.substr(valPos + 2));
        std::cout << line.substr(0, pos) << "=>" << value * btcValue << std::endl;
    }
    return 0;
}
