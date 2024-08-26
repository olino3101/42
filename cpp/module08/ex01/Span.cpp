#include "Span.hpp"

    Span::Span(int N) : N(N) {}
    Span::~Span() {}
    Span::Span() {}
    Span::Span(Span &other) : N(other.N) {}
    Span& Span::operator=(Span &other) {
        if (this != &other)
            N = other.N;
        return *this;
    }

    void Span::addNumber(int nbr) {
        try {
            if (numbers.size() == N)
                throw std::runtime_error("limit reach");
            numbers.push_back(nbr);
        }
        catch (std::exception &e) {
            std::cout << "Erreur: " << e.what() << std::endl;
        }
    }

    int Span::shortestSpan() {
        int shortest = std::numeric_limits<int>::max();
        bool thesame = false;
        if (numbers.size() == 1)
            return 0;
        for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        {
            for (std::vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i)
            {
                if (*it == *i && thesame == false && (thesame = true))
                    continue;
                else if (thesame == true && *it == *i)
                    return 0;
                int check_shortest = std::abs(*i - *it);
                if (check_shortest < shortest)
                    shortest = check_shortest;
            }
            thesame = false;
        }
        return shortest;
    }
    int Span::longestSpan() {
        int longest = 0;
        for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        {
            for (std::vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i)
            {
                int check_longest = std::abs(*i - *it);
                if (check_longest > longest)
                    longest = check_longest;
            }
        }
        return longest;
    }

    void Span::lotsOfNbr(int ammount) {
        try {
            if (numbers.size() + ammount > N)
                throw std::runtime_error("the ammount is too big");
        }
        catch (std::exception & e) {
            std::cout << "Erreur: " << e.what() << std::endl;
            return ;
        }
        std::vector<int> add;
        struct timeb timeStruct;
        ftime(&timeStruct);
        unsigned int seed = static_cast<unsigned int>(timeStruct.time) + timeStruct.millitm;
        std::srand(seed);
        for (int i = 0; i < ammount; i++)
        {
            int random_number = rand() % 10;
            add.push_back(random_number);
        }
        numbers.insert(numbers.end(), add.begin(), add.end());
    }

    static void printValue(int value) {
        std::cout << value << std::endl; 
    }
    void Span::printvec() {
        std::for_each(numbers.begin(), numbers.end(), printValue);
    }
