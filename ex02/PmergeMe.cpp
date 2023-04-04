# include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& copy){}

PmergeMe& PmergeMe::operator=(const PmergeMe& in)
{
    return (*this);
}

void PmergeMe::mergeVec(int a, int b, int m)
{
    int left_size = m - a + 1;
    int right_size = b - m;
    std::vector<int> left(left_size), right(right_size);
    int i = 0;
    int j = 0;
    while (i < left_size)
    {
        left[i] = this->vec[a+i];
        i++;
    }
    while (j < right_size)
    {
        right[j] = this->vec[m+1+j];
        j++;
    }
    i = 0;
    j = 0;
    int k = a;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            this->vec[k] = left[i];
            i++;
        }
        else
        {
            this->vec[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < left_size)
    {
        this->vec[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        this->vec[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeInsertVec(int a, int b)
{
    if (a >= b)
        return;
    int m = (a + b - 1) / 2;
    mergeInsertVec(a, m);
    mergeInsertVec(m+1, b);
    mergeVec(a, b, m);
}

void PmergeMe::printOut(int argc, char **argv)
{
    std::cout << "Before: " ;
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
    std::cout << "After: " ;
    for (int j = 0; j < this->vec.size(); j++)
        std::cout << this->vec[j] << " ";
    std::cout << std::endl;
}

void PmergeMe::checkConvert(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                std::cout << "err" << std::endl;
                exit(EXIT_FAILURE);
            }
            j++;
        }
        j = 0;
        i++;
    }
    i = 1;
    while(i < argc)
    {
        this->vec.push_back(atoi(argv[i]));
        i++;
    }
    clock_t start = clock();
    mergeInsertVec(0, this->vec.size() - 1);
    clock_t end = clock();
    printOut(argc, argv);
    double dur = double(end - start) / CLOCKS_PER_SEC;
    double dur_m = dur * 1000000;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << dur_m << "us" << std::endl;
}

    // for (i = 0; i < n1; i++)
    //     L.push_back(arr[l + i]);
    // for (j = 0; j < n2; j++)
    //     R.push_back(arr[m + 1 + j]);