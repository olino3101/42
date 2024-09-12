#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char **argv) {
    nbrs = std::string(argv[1]);
}
RPN::RPN(const RPN & other) : nbrs(other.nbrs) {

}
RPN& RPN::operator=(const RPN & other) {
    if ( this != &other)
    {
        nbrs = other.nbrs;
    }
    return *this;
}
bool RPN::calculate_stack(char op)
{
    int result;
    if (!(stack.size() >= 2))
    {
        std::cout << "error with operation logic" << std::endl;
        return false;
    }
    int first = stack.top();
    stack.pop();
    int second = stack.top();
    stack.pop();
    switch (op) {
        case '+':
            result = first + second;
            break;
        case '/':
            result = second / first;
            break;
        case '*':
            result = first * second;
            break;
        case '-':
            result = second - first;
            break;
    }
    stack.push(result);
    return true;
}

void RPN::add_stack(char nbr)
{
    stack.push(nbr - 48);
}

void RPN::calculate(void) {
    
    for (size_t i = 0; i < nbrs.length(); i++)
    {
        if (nbrs[i] == ' ')
            continue;
        else if (nbrs[i] == '-' || nbrs[i] == '/' || nbrs[i] == '*' || nbrs[i] == '+')
        {
            if (!calculate_stack(nbrs[i]))
                return ;
        }
        else if (std::isdigit(nbrs[i]) && std::isdigit(nbrs[i + 1]))
        {
            std::cout << "input nbr bigger than 9" << std::endl;
            return ;
        }
        else if (std::isdigit(nbrs[i]))
            add_stack(nbrs[i]);
        else {
            std::cout << "wrong character" << std::endl;
            return ;
        }
    }
    std::cout << stack.top() << std::endl;
}