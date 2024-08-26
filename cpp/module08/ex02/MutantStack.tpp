#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
    MutantStack<T>::~MutantStack() { }

 template <typename T>
    MutantStack<T>::MutantStack(const MutantStack & other) : std::stack<T>(other) { }

template <typename T>
    MutantStack<T>& MutantStack<T>::operator=(const MutantStack & other) {
        if (&other != this)
        {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

template <typename T>
    MutantStack<T>::MutantStack() { }
    
template <typename T>
    void MutantStack<T>::PrintStack() {
        std::stack<T> newStack(*this);
        for (size_t i = 0; i < this->size(); i++)
        {
            std::cout << newStack.top() << std::endl;
            newStack.pop();
        }
    }

// ITERATOR





template <typename T>
    typename MutantStack<T>::iterator MutantStack<T>::begin() {
        return (this->c.begin());
    }

template <typename T>
    typename MutantStack<T>::iterator MutantStack<T>::end() {
        return (this->c.end());
    }

#endif 