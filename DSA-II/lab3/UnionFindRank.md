Write a menu driven program for implementing a Union Find data structure with path compression and union by rank. A positive integer n is taken as the first line of the input and it is assumed that the universal set contains elements 1 to n. After reading n, the program will create n singleton sets using Makeset operations.

The main menu will have options 1: Find 2: Union 3: Print and 4:Exit. 

If the user gives option 1, then the next input will be the element x on which find(x) is to be called. The representative (that is the root) of the set containing x is printed as response. 

If the user gives option 2, then the next input will be a pair of elements x and y, separated by a space. The representative of the new set containing both x and y after the union operation and the resultant rank of the representative are printed as response, with a space separating them. Note that the result of the find operations done inside the union operation are not to be printed. 

If the user gives option 3, the response consists of n lines where,  in the ith line the element and its representative are printed, with a space separating them.

If the user gives option 4, the program is terminated.

SAMPLE INPUT/OUTPUT

Input:
6
3
1
3
2
2 5
2
4 6
2
6 2
3
1
5
3
2
3 1
2
2 3
3
1
1
3
4
Output:

1 1
2 2
3 3
4 4
5 5
6 6
3
2 1
4 1
4 2
1 1
2 4
3 3
4 4
5 4
6 4
4
1 1
2 4
3 3
4 4
5 4
6 4
3 1
4 2
1 4
2 4
3 4
4 4
5 4
6 4
4
1 4
2 4
3 4
4 4
5 4
6 4