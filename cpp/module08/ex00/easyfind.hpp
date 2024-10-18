#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>
# include <list>

template <typename T>
int * easyfind(T &a, int nbr) {
    typename T::iterator findNbr = std::find(a.begin(), a.end(), nbr);
    if (findNbr == a.end())
    {
    	throw std::exception() ;
    }
    return &(*findNbr);
}



#endif