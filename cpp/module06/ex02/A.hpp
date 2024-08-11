#pragma once

#include "Base.hpp"
#include <iostream>

class A : public Base {
    void print() const override { std::cout << "Class A" << std::endl; }
};