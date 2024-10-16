#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(new T()), sizeArr(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), sizeArr(n) {}

template <typename T>
T& Array<T>::operator[](unsigned int i) const {
    if (i >= sizeArr)
        throw OutOfBound();
    return arr[i];
}

template <typename T>
size_t Array<T>::size() const {
    return sizeArr;
}

template <typename T>
Array<T>::~Array() { 
    delete [] arr; 
}

template <typename T>
Array<T>& Array<T>::operator=(const Array & other) {
    if (&other != this)
    {
        delete [] arr;
        arr = new T[other.size()];
        sizeArr = other.size();
        for (int i = 0; i < sizeArr; i++)
            arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
Array<T>::Array(const Array & other) : arr(new T[other.size()]), sizeArr(other.size()) {
    for (int i = 0; i < sizeArr; i++)
        arr[i] = other.arr[i];
}


#endif 