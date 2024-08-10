#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Conv {
public :
    ~Conv();
    Conv(std::string);
    Conv(const Conv & other);
    Conv& operator=(const Conv & other);
    void converter();
private :
    Conv();
    std::string str;
};

#endif