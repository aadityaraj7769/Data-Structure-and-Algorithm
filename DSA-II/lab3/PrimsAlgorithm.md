Write a C program that takes a weighted undirected connected graph G and a vertex v of G as input and computes a minimum spanning tree of G using Prim's algorithm, with vertex v as the vertex from which the spanning tree construction is started. 

Use a min-heap based implementation of Prim's algorithm. Your algorithm must work in O(n log n + m log n) time complexity and only an additional O(n) space for processing, other than the O(m+n) space for the adjacency list (where n is the number of vertices of G and m is its number of edges). 

Input format : 

Line 1 : Number of vertices (assume vertices are numbered 1 to n).

Line i+1, where 1<=i<=n : The list of out neighbours and the edge weights of vertex i, where each out neighbour is followed by the corresponding edge weight.  Each value should be separated by a space and the line should end with a -1.  If the list is empty, the line would contain only a -1. 

Line n+2 : Source vertex s.

Output format : 

Line i, where 1 <= i <= n-1 : The endpoints of the ith edge added to the spanning tree and its weight, separated by spaces. The endpoint printed first should be the one which belonged to S (which is the connected part of the extendible forest as per our notation) and the endpoint printed second should be the one that was in V \ S. 



Sample Input:
4
2 6 3 5 4 4 -1
1 6 3 2 4 10 -1
1 5 2 2 4 3 -1
1 4 2 10 3 3 -1
1

Output:

1 4 4
4 3 3
3 2 2