#include<stdio.h>
#include<stdlib.h>

struct node{
    int item;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr tops;
// If the list is null , print empty ,,,else print non empty
void isempty()
{
        if(tops == NULL)
        {
            printf("Empty\n");
        }
        else{
            printf("Non Empty\n");
        }
    
}

void push(int n)
{
    nodeptr temp; //create new node temp and allocate memory
    temp = (nodeptr)malloc(sizeof(struct node));
    //Check if stack is full than inserting an element would lead to stack overflow
    if(!temp)
    {
        printf("Push Failure\n");
        exit(1);
    }
    else
    {
        temp->item = n; //initialize temp item be n
        temp->next = tops; //and temp->next stores the address of tops
        tops = temp; //and finally tops be temp
    }
}

void pop()
{
    //Create new node temp
    nodeptr temp;
        if(tops == NULL) // If the list is null then print Pop Failure
        {
            printf("Pop Failure\n");
        }

        else{
            printf("%d\n",(*tops).item); // else print top element
            temp = tops; //And assign temp to tops
            tops = tops->next; //tops will shift by one position
            temp->next = NULL; //temp will be independent
            free(temp); //finally free temp
        }
        
}

void Top()
{
        printf("%d\n",(*tops).item); //print the top element
}

void display()
{
    nodeptr temp; //create new node temp
    
    if(tops == NULL) //If list is empty then print empty list
    {
        printf("Empty List\n");
    }
    else{  
        temp = tops; //else assign temp to tops
        while(temp != NULL) //While temp is not equal to null , print the element
        {
            printf("%d\n",(*temp).item);
            temp = temp->next; 
        }
    }
}

void Exit(nodeptr newptr, int y)
{
    if(y==5)
    {
        exit(1);
    }
}

int main()
{
    int x,n;
    nodeptr  newptr;

    while(1)
    {
        scanf("%d",&x);
        //x = 0 ->>> Corresponds to the list is empty or not
        //->> calling isempty function
        if(x==0)
        {
            isempty();
        }

        //x = 1 ->>> Corresponds to take input from users and makes a linked list
        else if(x==1)
        {
            newptr = (nodeptr) malloc(sizeof(struct node)); // stores space using malloc function 
            int n;
            scanf("%d",&n);
            push(n);
        }

        //x = 2 ->>> Corresponds to print the element in top and delete it
        else if(x==2)
        {
            pop();
        }
        //x = 3 ->>> Corresponds to print the element in top
        else if(x==3)
        {
            Top();
        }
        //x = 4 ->>> Corresponds to print the rest element from top to bottom
        else if(x==4)
        {
            display();
        }
        //x = 5 ->>> Corresponds to exit from the program
        else if(x==5)
        {
            Exit(newptr , x);
        }

    }
    return 0;
}