Write a C program that takes a directed graph G as input and checks if it is a DAG or not,
using the algorithm discussed in class. In your DFS, whenever there is a choice to go to
a neighbour of a vertex being traversed, follow the input order of the neighbour list. Whenever
a new vertex is to be picked by the outer DFS function, follow the increasing order of vertex numbers. 

Input format :

Line 1 : Number of vertices (assume vertices are numbered 1 to n).

Line i+1, where 1<=i<=n : The list of outneighbours of vertex i,  followed by a -1, separated by one space each.

Line n+2 : Starting vertex for DFS

Output format :
  a) If the input graph is a DAG,
Line i, where 1 <= i <= n : Print the Entry time of vertex i, Exit time of vertex i, and the vertex number of the predecessor of vertex i, separated by one space each. If there is no predecessor, assume the default value to be -1.
Line n+1 : Print "DAG"
Line n+1+j, where 1 <=j<=n : Print j^th vertex as per the topological ordering produced by the algorithm.

 b) If the input graph is not a DAG,
Line i, where 1 <= i <= n : Print the Entry time of vertex i, Exit time of vertex i, and the vertex number of the predecessor of vertex i, separated by one space each. If there is no predecessor, assume the default value to be -1.
Line n+1 : Print "Not a DAG"
Line n+1+j, where 1 <=j <= number of backedges : If (u, v) is the j^th backedge as per the input order of the neighbour list and increasing order of vertex numbers, print the following four quantities, separated by one space each : Entry time of v, Entry time of u, Exit time of u, Exit time of v.

Constraints : Running time O(m+n), where n is the number of vertices and m is the number of edges of the input graph, additional space used : O(n), other than the O(m+n) space for the adjacency list.

Other instructions : Instead of using separate arrays for entry time, exit time, predecessor etc of vertices, include these as fields inside a structure defined for vertices.