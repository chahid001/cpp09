#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <stack>

class RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& in);
        void expEval(char *exp);
        int isOperand(char c);
        int isOperator(char c);
        int getStackTop();
        int calcOperation(int a, int b, char op);
};
#endif