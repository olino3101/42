#pragma once

#include "Base.hpp"

class B : public Base {
    void print() const override { std::cout << "Class B" << std::endl; }
};