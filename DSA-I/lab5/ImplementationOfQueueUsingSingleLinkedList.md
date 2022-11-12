Write a menu driven program that runs an infinite loop, asking the user to enter one of the following choices for manipulating a queue : 0: IsEmpty 1: Enqueue  2: Dequeue 3: Peek 4: Display from front to back 5: Exit. Assume the elements are integers. The IsEmpty, Enqueue, Dequeue, and Peek operations should work in O(1) time.  The Display operation should work in time proportional to number of elements in the queue. Write separate functions for each of these operations. Use an additional parameter error-code in Enqueue, Dequeue, Peek, Display functions to identify if the operation succeeded or not.

After calling IsEmpty, if the list is empty, print "Empty" and otherwise print "Non Empty".
After calling Enqueue, take an integer as input from user, add it into the queue and return. If the operation failed, print "Enqueue Failure" and  exit the main program.
After calling Dequeue, the element removed from the queue has to be printed. If the operation failed, print "Dequeue Failure". 
The Peek function prints the front element of the queue.
When Display is called, if the list is empty, print "Empty List", else print the queue elements from front to back.             
