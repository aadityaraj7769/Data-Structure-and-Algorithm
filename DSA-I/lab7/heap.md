Write a menu driven C program to implement the standard operations of a min-heap data structure.  The menu options are: 1) Insert a new element 2) Delete an element of the given index 3) ExtractMin 4) Print heap 5) DecreaseKey 6) FindMin 7) Exit. 
The nodes in the heap should have non-negative integral data and the running time of each of the operations must be O(log n) where n is the number of elements in the heap. Assume the maximum size of the array A representing the heap to be 100.

Input-Output Format: The first line contains the value of n, the initial number of elements in the heap. The next n lines contain the n elements of the heap. The subsequent lines will contain integers corresponding to specific operations on the heap.

After reading the first n elements of the heap, build the heap.

Operation: 

Insert: Inserts a new element to the existing heap. Outputs "Operation Fail" if the operation was unsuccessful.
Delete: Deletes the element in the given index. Outputs "Operation Fail" if the operation was unsuccessful.
ExtractMin: Deletes the node with the least value and prints its value.
Print heap:. Outputs the elements of the heap in the increasing order of their indices in A, one element per line.
DecreaseKey: Decreases the value of the node in the given index to the new value given. Outputs "Operation Fail" if the operation was unsuccessful. 
FindMin: Outputs the minimum value in the heap.