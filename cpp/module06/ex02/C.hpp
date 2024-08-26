#pragma once

#include "Base.hpp"
#include <iostream>
class C : public Base {
    void print() const { std::cout << "Class C" << std::endl; }
};