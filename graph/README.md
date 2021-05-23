# Graph algorithms

## adjecencyMatrix.cpp

n - number of vertex\
m - number of edges\
create and print adjecency matrix\

## printTreeGraph.cpp

n - number of vertex\
next n - 1 string - edges\
You should canonically print graph(print array, where arr[i] - parent of i vertex(if i dont have parent - arr[i] = 0))\

## adjecencyList.cpp

n - number of vertex\
m - number of edges\
create and print adjecency list\

## printTreeGraph2.cpp

n - number of vertex\
then we have adjecency matrix(n\*n)\
You should canonically print graph(print array, where arr[i] - parent of i vertex(if i dont have parent - arr[i] = 0))\

## BFS.cpp

orgingize BFS(Breadth First Search)\
You have n and adjecency matrix(n\*n)\
You should print array of indeces(array mark)\
Each index(mark[i]) means when you visited that vertex(i)\

## DFS.cpp

orgingize DFS(Depth First Search)\
You have n and adjecency matrix(n\*n)\
You should print array of indeces(array mark)\
Each index(mark[i]) means when you visited that vertex(i)\

## railroads-highways.cpp

There are railroads and highways detween cities.\
n - number of vertex, m - number of edges\
x - from, y - to, t - type, p - price\
If you arrived to city by highway and want to go then by railroad,\
you should pay 10% of price of railroad more, and vice versa.\
Otherwise you should pay only price of the road.\
You should find lowest road from start to finish\
First sten - from start go to all verteces you can\
Then start dijkstra algorithm\

## minCostFlow.cpp

Find Min Cost Flow at the network(graph)\

## maxEdge.cpp

Find max cost edge from one vertex to another\
You should respond for m requests\
