#include<stdio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};

typedef struct node *nodeptr;

int main()
{
    nodeptr head = NULL;
    nodeptr newptr, curptr, ptr1;
    int x, n;

    scanf("%d",&n); //Enter the number of elements

    for(int i = 0; i<n; i++)
    {
        newptr = (nodeptr) malloc(sizeof(struct node));
        // Enter the item stored in newptr and its node is initally NULL
        if(newptr != NULL)
        {
            scanf("%d",&x);
            newptr->item = x;
            newptr->next = NULL;
        }

        if(i==0)
        {
            head = newptr; //If only one element then initialize head 
        }

        else{
        //If there is only one element and other element have to be add in it
            if(((*head).next == NULL)  )
            {
                if((*head).item <= (*newptr).item)  //If other element greater than previous
                {
                    head->next = newptr;
                }
                else{  //Other element less than previous 
                    newptr->next = head;
                    head = newptr;                
                }
            }
            else if((*head).item >= (*newptr).item)  //If there are more than one element in list and newptr is less than initial
            {
                newptr->next = head;
                head = newptr;
                
            }
            else{
                //locate the node before the point of insertion
                ptr1 = head;
                while(ptr1->next != NULL && ptr1->next->item < newptr->item)
                {
                    ptr1 = ptr1->next;
                }
                newptr->next = ptr1->next;
                ptr1->next = newptr;
            }
        }
    }
    //Print the required output
    curptr = head;
    for(int i = 0; i<n; i++)
    {
        printf("%d\n",(*curptr).item);
        curptr = curptr->next;
    }
    return 0;
}