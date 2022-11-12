Write a C program that takes a directed graph G with positive integer valued edge weights, and a vertex s of G as input and computes the shortest path distance from s to all vertices of G, using a min-heap based implementation of the Dijkstra's algorithm. Your algorithm must work in O(n log n + m log n) time complexity and only an additional O(n) space for processing, other than the O(m+n) space for the adjacency list (where n is the number of vertices of G and m is its number of edges). 

 Input format : 

Line 1 : Number of vertices (assume vertices are numbered 1 to n).

 Line i+1, where 1<=i<=n : The list of out neighbours and the edge weights of vertex i, where each out neighbour is followed by the corresponding edge weight.  Each value should be separated by a space and the line should end with a -1.  If the list is empty, the line would contain only a -1. 

Line n+2 : Source vertex s.

Output format :

 Line i, where 1 <= i <= n : If vertex i is reachable from s, print the distance to vertex i, predecessor of vertex i in a shortest s-v path, separated by one space each. Assume the predecessor of s is -1. If vertex i is unreachable from s, print "Unreachable".

Sample

input:
8
2 4 3 4 4 3 8 10 -1
7 2 -1
6 3 7 2 -1
5 2 -1
3 1 6 1 -1
-1
8 1 6 1 -1
-1
1

Output:
0 -1
4 1
4 1
3 1
5 4
6 5
6 2
7 7