#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(new T()), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), size(n) {}

template <typename T>
T& Array<T>::operator[](unsigned int i) const {
    if (i >= size)
        throw OutOfBound();
    return arr[i];
}

template <typename T>
size_t Array<T>::Size() const {
    return size;
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
        arr = new T[other.Size()];
        size = other.size();
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
Array<T>::Array(const Array & other) : arr(new T[other.Size()]), size(other.Size()) {
    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}


#endif 