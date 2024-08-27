#include "Iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, function<int>);
    printArr(arr, 5);

    float arr1[] = {1.864, 2.1231, 3.768, 4.42, 5.4546};
    iter(arr1, 5, function<float>);
    printArr(arr1, 5);

    char arr2[] = {'a', 'b', 'c'};
    iter(arr2, 3, function<char>);
    printArr(arr2, 3);
}