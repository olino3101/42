#include "Span.hpp"

int main()
{
    Span span(7);
    span.addNumber(4);
    // span.addNumber(8);
    // span.addNumber(10);
    // span.addNumber(45);
    // span.addNumber(12);
    // span.addNumber(1);
    // span.addNumber(6);
    span.lotsOfNbr(4);
    //span.addNumber(4);
    span.printvec();
    std::cout << "s " << span.shortestSpan() << std::endl;
    std::cout << "l " << span.longestSpan() << std::endl;
    return 0;
}