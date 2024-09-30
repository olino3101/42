#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include <list>
#include <iomanip>

#define D(x) std::cout << x << std::endl;

class sort {
    public:
    sort(char **argv);
    
    
    // helpersss

    void SortV();
    void SortL();

    private:

	//vector
    void printsortV(int w);
	void initV();
	void insertBsV(std::vector<int> &j);
    void createAV(int i);
	void createPairsV(int i);
	std::vector<std::vector<int> > pairsV;
    std::vector<int> bV;
    std::vector<int> aV;
	bool hasLeftOverV;
	int leftoverV;

	void initL();
	void insertBsL(std::list<int> &j);
    void printsortL(int w);
    void createAL(int i);
	void createPairsL(int i);
	std::list<std::list<int> > pairsL;
    std::list<int> bL;
    std::list<int> aL;
	bool hasLeftOverL;
	int leftoverL;

	double getTime();
	std::clock_t startTime;
	char **argv;
    sort();
	sort(const sort & other);
    sort & operator=(const sort & other);
};

#endif