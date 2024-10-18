#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>


class Span {
public :
    Span(int N);
    ~Span();
    Span(const Span &other);
    Span& operator=(const Span &other);
    void addNumber(int nbr);
    int shortestSpan();
    int longestSpan();
    void lotsOfNbr(int ammount);
    void printvec();
private :
    Span();
    std::vector<int> numbers;
    unsigned int N;
};
#endif