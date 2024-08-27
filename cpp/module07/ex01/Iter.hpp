#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T, typename Func>
void iter(T* arr, size_t size, Func f)
{
    size_t i = 0;
    while (i < size)
    {
        f(arr[i]);
        i++;
    }
}

template <typename T>
void function(T &value)
{
    value += 1;
}

template <typename Arr>
void printArr(Arr arr, size_t size) {
    size_t i = 0;
    while (i < size)
    {
        std::cout << arr[i] << std::endl;
        i++;
    }
}

#endif