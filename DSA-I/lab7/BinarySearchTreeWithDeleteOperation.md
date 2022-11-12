Q2. Write a menu driven program for operating with a binary search tree. 
Initially start with an empty tree.
The menu options required are : 1) Insert an Element 2) Search for an Element 
3) Inorder Traversal 4) Preorder Traversal 5) Postorder Traversal 6) Find Predecessor of an Element 
7) Find Successor of an Element 8) Delete an element 9) Exit 
If a key x is appearing more than once in the tree, then for deleting x and for finding its 
successor and predecessor you may consider the node of x to be the node containing x that 
is depthwise closest to the root of the tree. If a node x with two children is to be deleted, 
then replace x with its inorder predecessor.
After receiving the options from the user, the program should invoke appropriate functions 
and use the result of the functions to give appropriate outputs.  Except for your traversal 
functions, your major functions are not supposed to print any messages. In these cases, to 
avoid cluttering your main function, you could define wrapper functions that process the results 
of calling your major functions and print the output messages.
Output Messages expected: 
1. If memory allocation failed during insertion, print "Insert Fail".
2. If search is successful, print "Found", otherwise print "Not Found".
3. For traversals, print elements in the appropriate order, one per line.
4. For successor/predecessor, if the element given is invalid, print "Invalid Input"; 
if successor(respectively, predecessor) does not exist, print "No successor" (respectively, 
"No predecessor"); Otherwise print the successor/predecessor in a newline of output.
5. If deletion is unsuccessful, print "Deletion Fail".