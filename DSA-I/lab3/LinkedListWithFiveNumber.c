#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
    int number;
    struct node *next;
}structs ;

int main()
{
    structs  x1,x2,x3,x4,x5,x6;
    structs  *head = NULL;
    structs *curptr, *ptr;

        scanf("%d\n%d\n%d\n%d\n%d",&x1.number,&x2.number,&x3.number,&x4.number,&x5.number); //taking input from users
        // initialize all the nodes after data be NULL
        x1.next = NULL;
        x2.next = NULL;
        x3.next = NULL;
        x4.next = NULL;
        x5.next = NULL;
    head = &x1; //head stores the address of 1st integer
    
    x1.next = &x2; //x1 node stores the address of 2nd integer and so on 
    x2.next = &x3;
    x3.next = &x4;
    x4.next = &x5;

    // curptr and ptr initially stores the address of 1st integer  
    curptr = head; 
    ptr = head;
    //print the data which had to be taken from users
    for(int i = 1; i<=5; i++)
    {
        printf("%d\n", (*curptr).number);
        curptr = (*curptr).next;
    }
    
    scanf("%d",&x6.number); //taking input of new numbers and arrange in such a way that if any number is greater than this than it should be placed before that otherwise at last
    x6.next = NULL;
    //if all numbers greater than that than placed at last position
    if((x6.number>x1.number)&&(x6.number>x2.number)&&(x6.number>x3.number)&&(x6.number>x4.number)&&(x6.number>x5.number))
    {
        curptr = head;
        x5.next = &x6;
        for(int i = 1; i<=6; i++)
        {
            printf("%d\n", (*curptr).number);
            curptr = (*curptr).next;
        }
        exit(1);
    }
    //new numbers placed at the beginning
    if((x6.number<x1.number))
    {
        head = &x6;
        x6.next = &x1;
        curptr = head;
        for(int i = 1; i<=6; i++)
        {
            printf("%d\n", (*curptr).number);
            curptr = (*curptr).next;
        }
exit(1);
    }
    //placed in between the list
    curptr=head;
     
    while(x6.number>(*curptr).number)
    {
        ptr = curptr;
        curptr = (*curptr).next;
        
    }
    //node of new data stores the address of just after that data
    x6.next = curptr;
    //and the address of new number stores in just before this data
    (*ptr).next = &x6;
    //print the output 
    ptr=head;
    for(int i = 1; i<=6; i++)
    {
        printf("%d\n", (*ptr).number);
        ptr = (*ptr).next;
    }
    

    return 0;
}