#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        BitcoinExchange test;
        test.readDb();
        test.readParse(argv[1]);
    }
    else
        std::cout << "Error: could not open file." << std::endl;
}