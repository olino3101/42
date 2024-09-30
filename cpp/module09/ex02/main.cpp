#include <iostream>
#include "PmergeMe.hpp"

bool check_arg(int argc, char **argv)
{
    if (argc <= 1)
    {
        std::cout << "wrong number of arguments" << std::endl;
        return false;
    }
	std::vector<int> checkdup;
	int nbr;
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
        	{
        	    std::cout << argv[i][j]<< "wrong input containz non numeric character" << std::endl;
        	    return false;
        	}
		}
		std::string nbrConv(argv[i]);
        std::stringstream ss(nbrConv);
        ss >> nbr;
		std::vector<int>::iterator it = std::find(checkdup.begin(), checkdup.end(), nbr);
		if (it != checkdup.end())
		{
			std::cout << "you have enter a duplicate" << std::endl;
			return false;
		}
		checkdup.push_back(nbr);
	}
    return true;
}

int main(int argc, char **argv)
{
    if (!check_arg(argc, argv))
        return false;
    sort algo(argv);
    algo.SortV();
    algo.SortL();

}