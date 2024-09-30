#include "PmergeMe.hpp"

sort::sort(const sort & other)  { (void)other;}
sort & sort::operator=(const sort & other) {
	(void)other;
	return *this;
}

double sort::getTime() {
	std::clock_t endTime = std::clock();
	double duration = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	return duration;
}

void sort::printsortV(int w)
{
    if (w == 1)
    {
        std::cout << "before : " << std::endl;
        for (int i = 0; (int)bV.size() != i; i++) {
        std::cout << bV[i] << ", ";
		}
		std::cout << std::endl;
    }
    else {
        std::cout << "after : " << std::endl;
        for (int i = 0; (int)aV.size() != i; i++) {
        std::cout << aV[i] << ", ";
    }
        std::cout << std::endl;
    }
}
void sort::printsortL(int w)
{
    if (w == 1)
    {
		std::list<int>::iterator it = bL.begin();
        std::cout << "before : " << std::endl;
        for (int i = 0; (int)bL.size() != i; i++) {
        	std::cout << *it << ", ";
			std::advance(it, 1);
		}
		std::cout << std::endl;
    }
    else {
		std::list<int>::iterator it = aL.begin();
        std::cout << "after : " << std::endl;
        for (int i = 0; (int)aL.size() != i; i++) {
        	std::cout << *it << ", ";
			std::advance(it, 1);
    	}
        std::cout << std::endl;
    }
}
int getElement(std::list<int> ls, int index) {
	std::list<int>::iterator it = ls.begin();
	std::advance(it, index);
	return *it;
}

static std::list<int> generateJacobsthalL(int n) {
    std::list<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    for (int i = 2; i < n; ++i) {
        jacobsthal.push_back(getElement(jacobsthal, i - 1) + getElement(jacobsthal, i - 2));
    }
    return jacobsthal;
}
static std::vector<int> generateJacobsthalV(int n) {
    std::vector<int> jacobsthal(std::max(n, 2));
    jacobsthal[0] = 0;
    jacobsthal[1] = 1;
    for (int i = 2; i < n; ++i) {
        jacobsthal[i] = jacobsthal[i-1] + jacobsthal[i-2];
    }
    return jacobsthal;
}

sort::sort(char **argv) : hasLeftOverV(false), hasLeftOverL(false), argv(argv)  {}

void sort::createPairsV(int i) {
	std::vector<int> pair;

	if (bV[0] < bV[1])
		std::swap(bV[0], bV[1]);
	pair.push_back(bV[0]);
	pair.push_back(bV[1]);
	bV.erase(bV.begin());
	bV.erase(bV.begin());
	pairsV.insert(std::upper_bound(pairsV.begin(), pairsV.end(), pair), pair);
	if (bV.size() >= 2)
		createPairsV(++i);
	else if (bV.size() == 1)
	{
		leftoverV = bV[0];
		hasLeftOverV = true;
		bV.erase(bV.begin());
	}
}

void sort::createAV(int i) {
	if (i == 0)
		aV.push_back(pairsV[0][1]);
    if (i < (int)pairsV.size())
    {
        aV.push_back(pairsV[i][0]);
		if (i != 0)
			bV.push_back(pairsV[i][1]);
        createAV(++i);
    }
}

void sort::insertBsV(std::vector<int> &j) {
	bool finish = false;
	for (int e = 1; e != (int)j.size(); e++)
	{
		int maxPairIndex = j[e] - 1;
		int minPairIndex = j[e - 1];
		if (maxPairIndex >= (int)bV.size())
		{
			maxPairIndex = bV.size() - 1;
			finish = true;
		}
		while (maxPairIndex >= minPairIndex)
		{
			std::vector<int>::iterator pos = std::upper_bound(aV.begin(), aV.end(), bV[maxPairIndex]);
			if (pos == aV.end())
				aV.insert(aV.begin(), bV[maxPairIndex]);
			aV.insert(pos, bV[maxPairIndex]);
			maxPairIndex--;
		}
		if (finish)
			break;
	}
}

void sort::initV() {
	int nbr;
    int i = 1;
    while (argv[i])
    {
        std::string nbrConv(argv[i]);
        std::stringstream ss(nbrConv);
        ss >> nbr;
        bV.push_back(nbr);
        i++;
    }
		if (i == 2)
			throw std::runtime_error("only one number");
}

void sort::initL() {
	int nbr;
    int i = 1;
    while (argv[i])
    {
        std::string nbrConv(argv[i]);
        std::stringstream ss(nbrConv);
        ss >> nbr;
        bL.push_back(nbr);
        i++;
    }
	if (i == 2)
		throw std::runtime_error("only one number");
}


void sort::insertBsL(std::list<int> &j) {
	bool finish = false;
	for (int e = 1; e != (int)j.size(); e++)
	{
		int maxPairIndex = getElement(j, e) - 1;
		int minPairIndex = getElement(j, e - 1);
		if (maxPairIndex >= (int)bL.size())
		{
			maxPairIndex = bL.size() - 1;
			finish = true;
		}
		while (maxPairIndex >= minPairIndex)
		{
			std::list<int>::iterator pos = std::upper_bound(aL.begin(), aL.end(), getElement(bL, maxPairIndex));
			if (pos == aL.end())
				aL.insert(aL.begin(), getElement(bL, maxPairIndex));
			aL.insert(pos, getElement(bL, maxPairIndex));
			maxPairIndex--;
		}
		if (finish)
			break;
	}
}

static void swapL(std::list<int>& b)
{
	std::list<int>::iterator beg = b.begin();
	std::list<int>::iterator one = b.begin();
	std::advance(one, 1);
	std::swap(*beg, *one);
}
void sort::createPairsL(int i) {
	std::list<int> pair;
	if (getElement(bL, 0) < getElement(bL, 1))
		swapL(bL);
	pair.push_back(*bL.begin());
	pair.push_back(getElement(bL, 1));
	bL.erase(bL.begin());
	bL.erase(bL.begin());
	pairsL.insert(std::upper_bound(pairsL.begin(), pairsL.end(), pair), pair);
	if (bL.size() >= 2)
		createPairsL(++i);
	else if (bL.size() == 1)
	{
		leftoverL = *bL.begin();
		hasLeftOverL = true;
		bL.erase(bL.begin());
	}
}

static int getElementDoubleLs (std::list< std::list<int> > pairs, int firstI, int secondI)
{
	std::list< std::list<int> >::iterator pair = pairs.begin();
	std::advance(pair, firstI);
	std::list<int>::iterator singleE = pair->begin();
	std::advance(singleE, secondI);
	return *singleE;
}

void sort::createAL(int i) {
	if (i == 0)
		aL.push_back(getElementDoubleLs(pairsL, 0, 1));
    if (i < (int)pairsL.size())
    {
        aL.push_back(getElementDoubleLs(pairsL, i, 0));
		if (i != 0)
			bL.push_back(getElementDoubleLs(pairsL, i, 1));
        createAL(++i);
    }
}

void sort::SortV() {
	double duration;
	startTime = std::clock();
	try {
		initV();
		printsortV(1);
		createPairsV(0);
		createAV(0);
    	std::vector<int> j = generateJacobsthalV(aV.size());
		insertBsV(j);
		if (hasLeftOverV)
			aV.insert(std::upper_bound(aV.begin(), aV.end(), leftoverV), leftoverV);
   	 printsortV(0);
	}
	catch(std::exception & e)
	{
		duration = getTime();
		std::cout << "Execution time: " << std::fixed << std::setprecision(6) << duration 
		<< " seconds with a range of: " << 1 << " with std::vector<int>" << std::endl;
		return ;
	}
	duration = getTime();
	std::cout << "Execution time: " << std::fixed << std::setprecision(6) << duration << " seconds with a range of: " << aV.size() 
	<< " with std::vector<int>" << std::endl;
}

void sort::SortL() {
	double duration;
	startTime = std::clock();
	try {
		initL();
		printsortL(1);
		createPairsL(0);
		createAL(0);
		std::list<int> j = generateJacobsthalL(aV.size());
		insertBsL(j);
		if (hasLeftOverL)
			aL.insert(std::upper_bound(aL.begin(), aL.end(), leftoverL), leftoverL);
   	 	printsortL(0);
	}
	catch(std::exception & e)
	{
		duration = getTime();
		std::cout << "Execution time: " << std::fixed << std::setprecision(6) << duration 
		<< " seconds with a range of: " << 1 << " with std::list<int>" << std::endl;
		return ;
	}
	duration = getTime();
	std::cout << "Execution time: " << std::fixed << std::setprecision(6) << duration << " seconds with a range of: " << aV.size() 
	<< " with std::list<int>" << std::endl;
}