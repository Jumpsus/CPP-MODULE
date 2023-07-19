#include "RPN.hpp"
#include "utils.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN &other):StackRPN(other.StackRPN)
{

}

RPN &RPN::operator=(const RPN &other)
{
    if (this == &other)
    {
        return (*this);
    }
    StackRPN = other.StackRPN;
    return(*this);
}

void    RPN::InsertExpression(float input)
{
    StackRPN.push(input);
}

bool    RPN::CalculateExpression(char oper)
{
    if (StackRPN.size() < 2)
        return false;

    float     second = StackRPN.top();
    StackRPN.pop();

    float     first = StackRPN.top();
    StackRPN.pop();

    switch (oper)
    {
        case '+':
            StackRPN.push(first + second);
            break ;
        case '-':
            StackRPN.push(first - second);
            break ;
        case '*':
            StackRPN.push(first * second);
            break ;
        case '/':
            StackRPN.push(first / second);
            break ;
        default:
            return false;
    }
    return true;
}

std::stack<float>   RPN::GetStack()
{
    return (this->StackRPN);
}