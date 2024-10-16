#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public :
    Array();
    Array(unsigned int n);
    Array(const Array & other);
    ~Array();

    size_t size() const;

    Array<T>& operator=(const Array & other);
    T& operator[](unsigned int i) const;
    class OutOfBound : public std::exception {
        public :
        virtual const char* what() const throw() {
            return "Wrong index";
        }
    };
private :
    T *arr;
    size_t sizeArr;
};

template <typename T>
std::ostream& operator<<( std::ostream& out, const Array<T>& arr) {
    for ( unsigned int i = 0; i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}
    
#include "Array.tpp"

#endif