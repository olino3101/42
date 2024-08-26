#include "easyfind.hpp"

int main()
{
    std::cout << "vector" << std::endl;
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    easyfind(vec, 7);
    easyfind(vec, 4);

    std::cout << "list" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    easyfind(lst, 7);
    easyfind(lst, 4);
}