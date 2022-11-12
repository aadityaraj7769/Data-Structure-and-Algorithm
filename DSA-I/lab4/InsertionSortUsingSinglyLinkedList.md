Write a C program to read a number n followed by n integers from the user and create a sorted linked list \(L\) from the elements using repeated insertions as described below.

After the first iteration, \(L\) contains only the first input element.  In general, at the beginning of \(i^{th}\)  iteration, \(L\) contains the first \(i-1\) input elements in their ascending order. In the \(i^{th}\) iteration, the \(i^{th}\) input element is inserted into \(L\) just before the first element in \(L\) which is greater than it (or at the end of \(L\) if all elements in \(L\) are smaller than or equal to the element being inserted). After \(n\) iterations, the list \(L\) contains all input elements, in sorted order. 

After the last iteration, traverse the linked list and print its elements as output.
