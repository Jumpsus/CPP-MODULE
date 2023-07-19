#include "utils.hpp"
#include "RPN.hpp"
#include <iostream>
#include <stack>

int main(int argc, char** argv)
{

    if (argc != 2)
    {
        std::cout << "Usage: \"<Polish mathematical expression>\"" << std::endl;
        return (1);
    }

    std::string     *split = FtSplit(argv[1]);
    int             index = 0;

    RPN             rpn;

    while (split[index] != "")
    {
        if (split[index].length() > 1 || !(IsDigit(split[index]) || IsOperator(split[index])))
        {
            std::cerr << "Error" << std::endl;
            delete  []split;
            return (2);
        }

        if (IsOperator(split[index]))
        {
            bool success = rpn.CalculateExpression(*split[index].c_str());
            if (!success)
            {
                std::cerr << "Error" << std::endl;
                delete  []split;
                return (3);
            }
        } else {
            rpn.InsertExpression(std::atof(split[index].c_str()));
        }
        index++;
    }

    std::stack<float> result = rpn.GetStack();
    if (result.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        delete  []split;
        return (4);
    }
    std::cout << result.top() << std::endl;
    delete  []split;
    
    return (0);
}