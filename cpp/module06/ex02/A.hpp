#pragma once

#include "Base.hpp"
#include <iostream>

class A : public Base {
    void print() const { std::cout << "Class A" << std::endl; }
};