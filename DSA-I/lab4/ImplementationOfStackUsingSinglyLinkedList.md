Write a menu driven program that runs an infinite loop, asking the user to enter one of the following choices for manipulating a stack : 0: IsEmpty 1: Push  2: Pop 3: Top 4: Display from top to bottom 5: Exit. Assume the elements are integers. The IsEmpty, Push, Pop, and Top operations should work in O(1) time.  The Display operation should work in time proportional to number of elements in the stack. Write separate functions for each of these operations. Use an additional parameter error-code in Push, Pop,  Top, Display functions to identify if the operation succeeded or not.

After calling IsEmpty, if the list is empty, print "Empty" and otherwise print "Non Empty".
After calling Push, take an integer as input from user, push it into the stack and return. If the operation failed, print "Push Failure" and  exit the main program.
After calling Pop, the element popped from the stack has to be printed. If the operation failed, print "Pop Failure". 
The Top function prints the top element of the stack.
When Display is called, if the list is empty, print "Empty List", else print the stack elements from top to bottom.       