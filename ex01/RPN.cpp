#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& copy)
{
}

RPN& RPN::operator=(const RPN& in)
{
    return (*this);
}

int RPN::isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (-1);
}

int RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return (1);
    return (-1); 
}

int RPN::calcOperation(int a, int b, char op)
{
    if (op == '+')
        return (b+a);
    else if (op == '-')
        return (b-a);
    else if (op == '/')
    {
        if (a == 0)
        {
            std::cout << "Can't divide by zero" << std::endl;
            exit(EXIT_FAILURE);
        }
        return (b/a);
    }
    else
        return (b*a);
}

int RPN::getStackTop()
{
    return (this->stack.top());
}

void RPN::expEval(char *exp)
{
    int i = 0;
    int res;
    int nb;

    while (exp[i])
    {
        while (isspace(exp[i]))
            i++;
        if (isOperand(exp[i]) != -1)
        {
            nb = atoi (&exp[i]);
            if (nb >= 10)
            {
                std::cout << "Try a number less than 10" << std::endl;
                exit(EXIT_FAILURE);
            }
            this->stack.push(atoi(&exp[i]));
        }
        else if (isOperator(exp[i]) != -1)
        {
            if (this->stack.size() < 2)
            {
                std::cout << "Syntax error" << std::endl;
                exit(EXIT_FAILURE);
            }
            int a = this->stack.top();
            this->stack.pop();
            int b = this->stack.top();
            this->stack.pop();
            res = calcOperation(a, b, exp[i]);
            this->stack.push(res);
        }
        i++;
    }
    std::cout << getStackTop() << std::endl;
}


