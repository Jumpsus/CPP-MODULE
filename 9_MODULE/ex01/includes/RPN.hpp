#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void                InsertExpression(float input);
        bool                CalculateExpression(char oper);
        std::stack<float>   GetStack();
    private:
        std::stack<float>   StackRPN;
};

#endif