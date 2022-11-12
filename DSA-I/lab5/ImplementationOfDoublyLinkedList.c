#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int item;
    struct node *next, *prev;
} *nodeptr;


int main()
{
    nodeptr newptr, curptr,curptr1, head ,last;
    int n ,x;
    scanf("%d",&n);

    for(int i = 0; i<n; i++)
    {
        newptr = (nodeptr) malloc(sizeof(struct node));
        // Enter the item stored in newptr and its node is initally NULL
        if(newptr != NULL)
        {
            scanf("%d",&x);
            newptr->item = x;
            newptr->next = NULL;
            newptr->prev = NULL;
        }

        if(i==0)
        {
            head = newptr; //If only one element then initialize head as well as last
            last = newptr;
        }

        else{
            // else newptr connects to previous and newptr becomes last
            last->next = newptr;
            newptr->prev = last;
            last = newptr;
        }
    }

    //print the list in same order w.r.t input
    curptr = head;
    for(int i = 0; i<n; i++)
    {
        printf("%d\n",curptr->item);
        curptr = curptr->next;
    }

    //print the list in reverse order w.r.t input
    curptr = last;
    for(int i = 0; i<n; i++)
    {
        printf("%d\n",curptr->item);
        curptr = curptr->prev;
    }

    //If there are no element in list or only one element then we can't delete head and last element
    if(head == NULL || head == last)
    {
        exit(1);
    }
    else{
        //Deleting the head element
        nodeptr temp0, temp1;
        temp0 = head;
        head = head->next;
        head->prev = NULL;
        free(temp0);
    
        //Deleting the last element
        curptr = head;
        temp1 = last;
        last = last->prev;
        last->next = NULL;
        free(temp1);
    }

    //print the element in same order w.r.t input after deleting head and last element
    for(int i = 0; i<n-2; i++)
    {
        printf("%d\n",curptr->item);
        curptr = curptr->next;
    }

    //print the element in reverse order w.r.t input after deleting head and last element
    curptr1 = last;
    for(int i = 0; i<n-2; i++)
    {
        printf("%d\n",curptr1->item);
        curptr1 = curptr1->prev;
    }

    return 0;

}