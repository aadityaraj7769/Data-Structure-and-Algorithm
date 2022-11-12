#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
    int number;
    struct node *next;
}structs ;

int main()
{
    structs  x1,x2,x3,x4,x5;
    structs  *head0 = NULL;
    structs *curptr, *ptr, *newptr0, *newptr1, *lptr = NULL, *lpt = NULL;

        scanf("%d\n%d\n%d\n%d\n%d",&x1.number,&x2.number,&x3.number,&x4.number,&x5.number); //taking input from users
        // initialize all the nodes after data be NULL
        x1.next = NULL;
        x2.next = NULL;
        x3.next = NULL;
        x4.next = NULL;
        x5.next = NULL;
    head0 = &x1; //head stores the address of 1st integer
    
    x1.next = &x2; //x1 node stores the address of 2nd integer and so on 
    x2.next = &x3;
    x3.next = &x4;
    x4.next = &x5;

    curptr = head0; // let curptr stores the address of x1
    ptr = (*curptr).next; // ptr stores the address of next element of x1
    newptr0 = curptr; // let both are equal
    newptr1 = (*newptr0).next; // this stores the address of next of newptr0 
    
    /* Here I am doing such that we get the required output
        ->so at first i will print the first element
        ->after running loop 4 times- first for two elements, than for three element and so on
        ->sort the element during in loop
        ->and finally print the required output*/

    printf("%d\n", (*curptr).number); // first we print the first element
    int t=4, k=2;
    lptr = x2.next;//lptr stores the address of 3rd element
    while(t--)
    {
        lpt = lptr; // initialize lpt  to lptr
        int swa = 0;
        do{
            swa = 0;
            newptr0 = head0;
            newptr1 = (*newptr0).next;
            while(newptr0->next != lpt)
            {
                if((*newptr0).number > ((*newptr1).number ))
                {
                    int temp = (*newptr0).number;
                    (*newptr0).number = (*newptr1).number;
                    (*newptr1).number = temp;
                    swa = 1;
                }
                newptr0 = newptr0->next;
                newptr1 = newptr1->next;
            }
            lpt = newptr0;

        }while(swa);// After this loop ended , we will get the sorted list
        //Print the respective element element
            curptr = head0;
            for(int i = 1; i<=k; i++)
            {
                printf("%d\n", (*curptr).number);
                curptr = (*curptr).next;
            }
            k++; // increase element
            if(t!=0)
            {
                lptr = lptr->next; //this points to next pointer
            }    
    }
    return 0;
}