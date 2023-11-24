
# CPP Module 09

The C++ Module 09 delves into advanced concepts of the Standard Template Library (STL) through three comprehensive exercises. It emphasizes adhering to C++98 standards while exploring Object-Oriented Programming principles.

## Exercices

### Ex00

"Bitcoin Exchange," requires creating a program to calculate Bitcoin values based on a provided database, focusing on error handling and container usage.

#### Example of input file

```bash
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```
#### Deployement

```bash
$> make

$> ./btc
Error: could not open file.

$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>

```

### Ex01
"Reverse Polish Notation," involves developing a calculator using RPN, limiting numbers to less than 10 and handling basic operations.

#### Example of standard use and Deployement

```bash
$> make

$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>
```

### Ex02
"PmergeMe" necessitates implementing merge-insert sort algorithms with stringent requirements on container use and sorting large sets of positive integers.

#### Example of standard use and Deployement

```bash
$> make

$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us

$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us

$> ./PmergeMe "-1" "2"
Error

$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
```



