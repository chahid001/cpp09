#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        PmergeMe p;
        p.checkConvert(argc, argv);
    }
    else
        std::cout << "Please enter an argument" << std::endl;
}