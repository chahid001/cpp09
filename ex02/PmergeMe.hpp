#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstring>
# include <cstdlib>
# include <time.h>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& in);
        void checkConvert(int argc, char **argv);
        void mergeInsertVec(int a, int b);
        void mergeVec(int a, int b, int m);
        void printOut(int argc, char **argv);
};

#endif
