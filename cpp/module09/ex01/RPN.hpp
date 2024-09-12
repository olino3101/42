#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    public:
    void calculate(void);
    RPN(char **argv);
    RPN(const RPN & other);
    bool calculate_stack(char op);
    RPN& operator=(const RPN & other);
    private:
    RPN();
    void add_stack(char nbr);
    std::string nbrs;
    std::stack<int> stack;
};

#endif