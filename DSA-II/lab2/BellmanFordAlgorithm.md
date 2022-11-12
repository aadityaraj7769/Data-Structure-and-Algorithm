Write a C program that takes a weighted directed graph G, and a vertex s of G as input and computes the shortest path distance from s to all vertices of G using the Bellman-Ford algorithm which includes the update Flag based optimisation and negative cycle detection. If there is a negative weight cycle reachable from s in G, your program should print vertices of such a cycle in the order of the cycle. Your algorithm should work in O(n+mn) time and with only O(n) additional space, other than storing the input edge-list. It should work faster as expected if the algorithm converges in lesser number of rounds. 

 Input format : 

Line 1 : Number of vertices (assume vertices are numbered 1 to n). 

Line 2 : Number of edges (assume this number is m). 

Line 2+i, where 1<=i<=m : Endpoints of the ith edge of G and its  weight, separated by a space.

Line m+3: Source vertex, s

 Instructions: For edge relaxations, follow the same order as in the input edge-list. For printing negative weight cycle (if exists), consider the vertex v whose d value got updated earliest in the nth round of edge relaxations and retrace the predecessor pointers from v. If v itself is lying on a negative weight cycle, the order of printing the cycle vertices should be such that v is printed as the last vertex of the cycle. If v is not lying on a negative weight cycle, the order of printing the cycle vertices should be such that the vertex x of the cycle which is the first one to encounter while retracing the path predecessors from v is printed as the last vertex of the cycle.

 Output format :

 a. If the graph has no negative weight cycles reachable from s, then : 

Line i, where 1 <= i <= n : If vertex i is reachable from s, print the distance to vertex i, predecessor of vertex i in a shortest s-v path, separated by one space each. Assume the predecessor of s is -1. If vertex i is unreachable from s, print "Unreachable". 

 b. If the graph has negative weight cycles reachable from s, then print the vertices of the cycle as per the cyclic order, separated by one space each. To decide which cycle to print and in which order, follow the instructions given above.



Sample Input :
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3

1

Output:

0 -1
1 3
3 4
5 1
0 2
4 4
3 5