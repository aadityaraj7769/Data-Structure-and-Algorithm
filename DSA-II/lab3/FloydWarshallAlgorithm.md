Write a C program that takes the weight matrix of a weighted directed graph G as input and computes the shortest path distance between all pairs of vertices of G, using Floyd-Warshall algorithm. Your algorithm must work in O(n3) time complexity and only an additional O(n2) space for processing (where n is the number of vertices of G and m is its number of edges). 

Input format :

Line 1 : Number of vertices (assume vertices are numbered 1 to n).

Line i+1, where 1<=i<=n : The entries corresponding to the ith row of the edge weight matrix, separated by one space each. The entry corresponding to (i, i) would be zero. The entry corresponding to (i, j) would be the weight of the corresponding edge, if such an edge is present and would be 55555 otherwise. [ You may assume other path lengths are going to be less than this value].

Output format : 

Line 1 : Print "Pairwise Distance Matrix After Two Rounds"

Lines 2 to n+1 would print the entries in the intermediate distance matrix after the first two iterations of the main outer-loop (that is when a subset of {v1, v2} are allowed as intermediate vertices.  The format is as follows.

Line i+1, where 1 <= i <= n : The entries in ith row of the intermediate distance matrix after two rounds, separated by one space each. If vertex j is not reachable from i, print 55555 corresponding to that entry. 

Line n+2: Print "Pairwise Predecessor Matrix After Two Rounds"

Line n+2+i, where 1 <= i <= n : The entries in the ith row of the intermediate predecessor matrix after two rounds, separated by one space each. If vertex j is not reachable from i, print NIL corresponding to that entry. If i=j, the corresponding entry is NIL. 

Line 2n+3: Print "Final Pairwise Distance Matrix"

Line 2n+3+i, where 1 <= i <= n : The entries in the ith row of the final distance matrix, separated by one space each. If vertex j is not reachable from i, print 55555 corresponding to that entry.  

Line 3n+3 : Print "Final Pairwise Predecessor Matrix"

Line 3n+3+i, where 1 <= i <= n : The entries in ith row of the final predecessor matrix, separated by one space each. If vertex j is not reachable from i, print NIL corresponding to that entry. If i=j, the corresponding entry is NIL. 



Sample Input Output:

Input :

5

0 3 8 55555 -4

55555 0 55555 1 7

55555 4 0 -5 55555

2 55555 55555 0 55555

55555 55555 55555 6 0

output:

Pairwise Distance Matrix After Two Rounds

0 3 8 4 -4

55555 0 55555 1 7

55555 4 0 -5 11

2 5 10 0 -2

55555 55555 55555 6 0

Pairwise Predecessor Matrix After Two Rounds

NIL 1 1 2 1

NIL NIL NIL 2 2

NIL 3 NIL 3 2

4 1 1 NIL 1

NIL NIL NIL 5 NIL

Final Pairwise Distance Matrix

0 3 8 2 -4

3 0 11 1 -1

-3 0 0 -5 -7

2 5 10 0 -2

8 11 16 6 0

Final Pairwise Predecessor Matrix

NIL 1 1 5 1

4 NIL 1 2 1

4 1 NIL 3 1

4 1 1 NIL 1

4 1 1 5 NIL