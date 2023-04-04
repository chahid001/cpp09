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
    else if (op == '*')
        return (b*a);
    else
        return (b/a);
}

int RPN::getStackTop()
{
    return (this->stack.top());
}

void RPN::expEval(char *exp)
{
    char *c = strtok(exp, " ");
    while (c != NULL)
    {
        if (isOperand(c[0]) != -1)
        {
            int nb;
            nb = atoi(&c[0]);
            if (nb < 10)
                this->stack.push(nb);
            else
            {
                std::cout << "great than 10" << std::endl;
                exit(EXIT_FAILURE);
            }  
        }
        else if (strlen(c) == 1 && isOperator(c[0]))
        {
            if (this->stack.size() == 2)
            {
                int a,b, res;
                a = this->stack.top();
                this->stack.pop();
                b = this->stack.top();
                this->stack.pop();
                this->stack.push(calcOperation(a, b, c[0]));
            }
            else
                std::cout << "asd" << std::endl;

        }
        else
        {
            std::cout << "error" << std::endl;
            exit(EXIT_FAILURE);
        }
        c = strtok(NULL, " ");
    }
    int res = this->stack.top();
    std::cout << res << std::endl;
}


