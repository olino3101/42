#include "easyfind.hpp"

int main()
{
    std::cout << "vector" << std::endl;
    std::vector<int> vec;

	try {
    	vec.push_back(1);
    	vec.push_back(2);
    	vec.push_back(3);
    	vec.push_back(4);
    	vec.push_back(5);
    	// easyfind(vec, 7);
    	std::cout << *easyfind(vec, 4) << std::endl;
    	// std::cout << easyfind(vec, 18) << std::endl;
    	std::cout << easyfind(vec, 7) << std::endl;



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
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}