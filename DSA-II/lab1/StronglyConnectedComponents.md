Write a C program that takes a directed graph as input and computes the strongly connected components of
 G, as per the algorithm discussed in class. In your DFS of the input graph, whenever there is a choice 
 to go to a neighbour of a vertex being traversed, follow the input order of the neighbour list. Whenever
 a new vertex is to be picked by the outer DFS function for the input graph's DFS, follow the increasing
 order of vertex numbers. For the DFS of the reverse graph, while traversing the neighbour list of a
 vertex, follow the ascending order of the neighbour's vertex numbers. 

Input format :
Line 1 : Number of vertices (assume vertices are numbered 1 to n).
Line i+1, where 1<=i<=n : The list of outneighbours of vertex i, followed by a -1, separated by one
 space each. If the list is empty, the line would contain only a -1.
Line n+2 : Starting vertex for the DFS of the input graph

Output format : 
Line i, where 1 <=i <=n : List of outneighbours of vertex i in the reverse graph, in their ascending 
order, followed by a -1, separated by one space each. If the list is empty, the line should contain 
only a -1.
Line j, where 1 <=j <= number of strongly connected components of the input graph, where components
are ordered as per the decreasing order of their final values:
Vertices of j^th strongly connected component, ordered as per the order in which they were entered 
by the DFS on the reverse graph, separated by one space each.

Constraints : Running time O(m+n), where n is the number of vertices and m is the number of edges of 
the input graph, additional space used : O(n), other than the O(m+n) space for the adjacency lists of
 G and its reverse graph. 

Other instructions : Instead of using separate arrays for entry time, exit time, predecessor etc of 
vertices, include these as fields inside a structure defined for vertices.  