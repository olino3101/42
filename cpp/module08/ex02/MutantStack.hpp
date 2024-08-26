#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
public :
    
    ~MutantStack();
    MutantStack();
    MutantStack(const MutantStack & other);
    MutantStack<T>& operator=(const MutantStack & other);
    void PrintStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator end();
    iterator begin();
};

#include "MutantStack.tpp"

#endif
