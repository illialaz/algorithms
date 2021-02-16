# Recursion

## binStr.cpp - Count binary strings

n - length of binary string (n <= 10^6)\
k - number of 1 in string (k <= n)\
Find all strings that contains k ones and n - k zeroes\
Print that number MOD (10^9 + 7)\
(Problem is how to count n! where n is very big)\
Solution is to understand how to find ((a / b) mod c)\
Then use formula ((a \* b) mod c) = (((a mod c) \* (b mod c)) mod c)\
