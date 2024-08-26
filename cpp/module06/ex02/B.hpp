#pragma once

#include "Base.hpp"
#include <iostream>

class B : public Base {
    void print() const { std::cout << "Class B" << std::endl; }
};