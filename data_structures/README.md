## binSearch.cpp

n - number of elems in array\
next n elems - elems of array\
k - number of queries\
next k elems - elems to find\
print if elem is in array(0 or 1), lowerBound and upperBound\

## isBinHeap.cpp

n - num of elems
next n elem s - heap\
check if binary heap is correct(value of child >= value of current elem)\

## binHeap.cpp

n - num of elems\
find height of each tree in binomial heap\

# sumArray.cpp

arr - array
You can add number to arr[i] and count sum of array from i to j position with the help of tree\
It is very fast, it's complexity is around O(1)

## buildRoads.cpp && destroyRoads.cpp

Tasks are about DSU(Disjoint Set Union)\
you have cyties and roads between them.\
First task (buildRoads.cpp) is about "connected components",\
you should count num of them after adding each road.\
The next task(destroyRoads.cpp) is reversed. Tou have all the\ roads, it is one component, and each step you destroy one road.\ You should find, which step will be the last, after which your\ roads will be not one connected component.

## subsequence.cpp

You have sequence and number k\
k = 1: find max non decrease subsequence\
k = 2: find max subsequence, every neighbouring elements of which are coprime(gcd(a, b) > 1 if a, b are neighbours)\
k = 3: mix of 2 first, max non decrease subsequence, each neighbouring elements of which are coprime\

## hashTable.cpp

Create hashTable from input data and print it\
m - length of hashtable\
c - constant for hashFunc\
n - number of elems to add to hashtable\

## avlTree.cpp

n - len of first array
m - length of second array
You should get new array, which contains all elements from first array, except those,\
that are present in second sequence p times, where p is a prime number.

## blackbox.cpp

n - number of "Get" operations
m - number of "Add" operations
toFind - sorted array of numbers, in which time we should get number
toAdd - sequence of numbers which are already added

We have sequence of numbers which we should add.\
Then we have sequence of number when to get "i"(at start i = 0) number.\
If size of toAdd array equals to toFind[i] then you should increment i and find\
i element of sorted sequence of toAdd, else you should add next element to sequence toAdd)
