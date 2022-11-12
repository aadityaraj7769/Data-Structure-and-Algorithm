#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node0{
    char ch0;
    struct node0  *next,*left, *right;
} *nodeptr0;

nodeptr0 top;

void push(nodeptr0 temp)
{
    if(!temp) 
    {
        printf("Push Failure\n");
        exit(1);
    }
    else
    {
        temp->next = top; //temp->next stores the address of top
        top = temp; //and temp will be top
    }
}

void pop()
{
    //Create new node temp
    nodeptr0 temp;
    if(top == NULL) // If the list is null then exit from the program
    {
        exit(1);
    }    
    else{       
        temp = top; //And assign temp to tops
        top = top->next; //tops will shift by one position
        temp->next = NULL; //temp->next is NULL
    }
}

nodeptr0 Top()
{
    nodeptr0 z ;
        if(top == NULL) // If the list is null then exit from the program
        {
            exit(1);
        }
        z = top; //else z will be top and return z
        return z;
}

void Preorder(nodeptr0 root)
{
    if(root == NULL)
    {
        return;
    }
    else{ //first print key value then call left subtree then call right subtree
        printf("%c",root->ch0);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(nodeptr0 root)
{
    if(root == NULL)
    {
        return;
    }
    else{ //first call left subtree then print key value then call right subtree
        if(root->left != NULL && root->right != NULL)
        {
            printf("(");
        }
        Inorder(root->left);
        printf("%c",root->ch0);
        Inorder(root->right);
        if(root->left != NULL && root->right != NULL)
        {
            printf(")");
        }
    }
}

int main()
{
    char x, op[5] = {'+','-','*','/','^'},y;
    nodeptr0 oprnds,ops;
    int t;
    char str[50];
    scanf("%s",str); //taking input as a string
    t = strlen(str); //length of string
    for(int i = 0; i<t; i++)
    {
        if(str[i]!=op[0] && str[i]!=op[1] && str[i]!=op[2] && str[i]!=op[3] && str[i]!=op[4] ) // if any character is not equal to operator
        {
            oprnds = (nodeptr0)malloc(sizeof(struct node0)); //creating new node and initialize...
            oprnds->ch0 = str[i]; //data will be str[i]
            oprnds->left = NULL; //left pointer points to NULL
            oprnds->right = NULL; //right pointer points to NULL
            oprnds->next = NULL; //next pointer points to NULL
            push(oprnds); //calling push function
        }
        else{
            y = str[i]; //if str[i] is operator then y is equal to that

            ops = (nodeptr0)malloc(sizeof(struct node0)); //creating new node

            nodeptr0 T2 = Top(); //T2 is the top node in stack
            ops->right = T2; //and ops->right will be the T2
            pop(); //calling pop function

            nodeptr0 T1 = Top(); //T1 is the top node in stack
            ops->left = T1; //and ops->left will be the T1
            pop(); //calling pop function

            ops->ch0 = y; //and data will be operator
            ops->next = NULL; //next pointer points to NULL

            push(ops);  //calling push function
        }    
    }
    
    Inorder(ops); //for finding infix expression we have to go inorder traversal in expression tree

    printf("\n");

    Preorder(ops); //for finding prefix expression we have to go preorder traversal in expression tree
    return 0;
}