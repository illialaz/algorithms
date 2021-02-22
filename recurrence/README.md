# Recurrence

## binStr.cpp - Count binary strings

n - length of binary string (n <= 10^6)\
k - number of 1 in string (k <= n)\
Find all strings that contains k ones and n - k zeroes\
Print that number MOD (10^9 + 7)\
(Problem is how to count n! where n is very big)\
Solution is to understand how to find ((a / b) mod c)\
Then use formula ((a \* b) mod c) = (((a mod c) \* (b mod c)) mod c)\

## frog.cpp - Max number of mosquitoes that frog can eat

n - num of water lilies\
next n numbers - number of mosquitoes in each lily\
frog sits at the first lily\
frog can jump 2 or 3 lilies ahead\
in each lily it eats all the mosquitoes\
find max num of mosquitoes that frog can eat\
frog should be at the last lily after all jumps\

## mulMatrix.cpp

s - number of matrices\
next s strings - dim of matrices (n \* m)\
count min number of multiplications\

## binSearch.cpp

n - number of elems in array\
next n elems - elems of array\
k - number of queries\
next k elems - elems to find\
print if elem is in array(0 or 1), lowerBound and upperBound\
