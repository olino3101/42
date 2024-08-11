#pragma once

#include "Base.hpp"
#include <iostream>
class C : public Base {
    void print() const override { std::cout << "Class C" << std::endl; }
};