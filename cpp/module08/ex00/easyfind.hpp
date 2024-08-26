#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>
# include <list>

template <typename T>
typename T::iterator easyfind(T &a, int nbr) {
    typename T::iterator findNbr = std::find(a.begin(), a.end(), nbr);
    if (findNbr == a.end())
    {
        std::cout << "not found" << std::endl;
        return findNbr ;
    }
    std::cout << "found" << std::endl;
    return findNbr;
}



#endif