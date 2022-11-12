#include<stdio.h>
#include<stdlib.h>

struct node{
    int item;
    struct node *next;
} *first = NULL, *last = NULL; // Take two pointers where first address the first element and last address the last

typedef struct node *nodeptr;
// If the list is null , print empty ,,,else print non empty
void IsEmpty()
{
    if(first == NULL)
    {
        printf("Empty\n");
    }
    else{
        printf("Non Empty\n");
        }
}

void Enqueue(int n)
{
    nodeptr temp; //create new node temp and allocate memory
    temp = (nodeptr)malloc(sizeof(struct node));
    temp->item = n;
    temp->next = NULL;
    if(!temp) //Check if queue is full than inserting an element would lead to queue overflow
    {
        printf("Enqueue Failure\n");
        exit(1);
    }
    else{
        if(first == NULL)
        {
            first = last = temp; // If there is no element then first and last stores the same element 
        }
        
        else{
            last->next = temp; 
            last = temp;
        }
    }
}

void Dequeue()
{
    //Create new node temp
    nodeptr temp;
    if(first == NULL) // If the list is null then print Dequeue Failure
    {
        printf("Dequeue Failure\n");
    }

    else{
        printf("%d\n",first->item); // else print first element
        temp = first; //And assign temp to first
        first = first->next; //first will shift by one position
        free(temp); //finally free temp
    }
}

void Peek()
{
    printf("%d\n",first->item); //print the first element
}

void Display()
{
    nodeptr temp; //create new node temp
    
    if(first == NULL) //If list is empty then print empty list
    {
        printf("Empty List\n");
    }
    else{  
        temp = first; //else assign temp to first
        while(temp != NULL) //While temp is not equal to null , print the element
        {
            printf("%d\n",temp->item);
            temp = temp->next; 
        }
    }
}

void Exit() //exit from the program
{
    exit(1);
}

int main()
{
    int x, n;
    nodeptr newptr ;
    while(1)
    {
        scanf("%d",&x);
        //x = 0 ->>> Corresponds to the list is empty or not
        //->> calling IsEmpty function
        if(x==0)
        {
            IsEmpty();
        }
        
        //x = 1 ->>> Corresponds to take input from users and makes a linked list
        else if(x==1)
        {
            newptr = (nodeptr)malloc(sizeof(struct node)); // stores space using malloc function 
            int n;
            scanf("%d",&n);
            Enqueue(n);
        }

        //x = 2 ->>> Corresponds to print the element in first and delete it
        else if(x==2)
        {
            Dequeue();
        }

        //x = 3 ->>> Corresponds to print the element in first
        else if(x==3)
        {
            Peek();
        }
        
        //x = 4 ->>> Corresponds to print the rest element from first to last
        else if(x==4)
        {
            Display();
        }
        
        //x = 5 ->>> Corresponds to exit from the program
        else if(x==5)
        {
            Exit();
        }
    }
    return 0;
}