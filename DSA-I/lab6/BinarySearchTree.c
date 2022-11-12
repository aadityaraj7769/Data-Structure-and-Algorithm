 #include<stdio.h>
#include<stdlib.h>
 
struct node{
    int key;
    struct node *left, *right;
};

typedef struct node *nodeptr;
nodeptr root = NULL;

void Insert( int n) // inserting element in leaf
{
    int dir;
    nodeptr temp, prev = NULL, cur = root; //initialize cur to root
    temp = (nodeptr)malloc(sizeof(struct node));//create new node temp and allocate memory
    if(temp == NULL)
    {
        printf("Insert Fail\n");
        exit(1);
    }
    temp->key = n; 
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL) //If there is no element then temp will be the first element
    {
        root = temp;
    }

    else{
        while(cur != NULL) //if more than one element
        {
            if(n < cur->key)  //if key value is less than cur key value than prev is cur and cur will be one more depth towards left
            {
                prev = cur;
                cur = cur->left;
                dir = 0; //set direction to zero that means insert at left position
            }
            else{ //if key value is more than cur key value than prev is cur and cur will be one more depth towards right
                prev = cur;
                cur = cur->right;
                dir = 1; //set direction to one that means insert at right position
            }
        }
        if(dir == 0 )
        {
            prev->left = temp;
        }
        else{
            prev->right = temp;
        }
    }
}

int Search(nodeptr root , int t)
{
    int v;
    if(root == NULL) //if bst has no element then v is zero and return v
    {
        v = 0;
         return v;
    }
    else{
        if(t == root->key) //if key value is equal to root key value then v is one and return v
        {
            v = 1;
             return v;
        }
        else if(t < root->key) //if key value is less than root key value then recurrsively call left sub tree
        {
            Search(root->left , t); 
        }
        else{
            Search(root->right , t); //if key value is greater than root key value then recurrsively call left sub tree
        }
    }
   
}

void InorderTraversal(nodeptr root)
{

    if(root == NULL)
    {
        return;
    }
    else{ //first call left subtree then print key value then call right subtree
        InorderTraversal(root->left);
        printf("%d\n",root->key);
        InorderTraversal(root->right);
    }
}

void PreorderTraversal(nodeptr root)
{
    if(root == NULL)
    {
        return;
    }
    else{ //first print key value then call left subtree then call right subtree
        printf("%d\n",root->key);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

void PostorderTraversal(nodeptr root)
{
    if(root == NULL)
    {
        return;
    }
    else{ //first call left subtree then call right subtree then print key value
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d\n",root->key);
    }
}

void Predecessor(nodeptr root ,nodeptr pred, int z)
{
    nodeptr tem = NULL;
    if(root == NULL)
    {
        return;
    }
    // If key is present at root
    if(root->key == z)
    {
        if(root->left != NULL) //maximum value of left subtree will be predecessor
        {
            nodeptr temp1 = root->left;
            while(temp1->right != NULL)
            {
                temp1 = temp1->right;
                
            }
            pred = temp1;
        }
    }
    //if key value is less than the root then recurrsive call for left subtree
    else if (z < root->key) {
    return Predecessor(root->left, pred, z);
    }
    else{ //if key value is more than the root then recurrsive call for right subtree
            //update the pred to the current node before calling
            pred = root;
            return Predecessor(root->right, pred, z);
    }
    tem = pred;
    
    if(tem == NULL)
    {
        printf("No predecessor\n");
    }
    else{
        printf("%d\n",tem->key);
    }
}

void Successor(nodeptr root, nodeptr suc,int c)
{
    nodeptr tem0 = NULL;
    if(root == NULL)
    {
        return;
    }
    // If key is present at root
    if(root->key == c)
    {
        if(root->right != NULL) //minimum value of right subtree will be successor
        {
            nodeptr temp2 = root->right;
            while(temp2->left != NULL)
            {
                temp2 = temp2->left;
                
            }
            suc = temp2;
        }
    }
    //if key value is more than the root then recurrsive call for right subtree
    else if(c > root->key)
    {
        return Successor(root->right, suc , c);
    }
    //if key value is less than the root then recurrsive call for left subtree
    //update the suc to the current node before calling
    else{
        suc = root;
        return Successor(root->left,suc,c);
    }
    tem0 = suc;
    
    if(tem0 == NULL)
    {
        printf("No successor\n");
    }
    else{
        printf("%d\n",tem0->key);
    }
}

int main()
{
    int x, n , t;
    nodeptr newptr, ptr ,pred = NULL, suc = NULL;
    
    while(1)
    {
        scanf("%d",&x); // taking input

        if(x==1)
        {
            newptr = (nodeptr)malloc(sizeof(struct node));
            scanf("%d",&n); //element to be insert in bst
            Insert(n);
        }
        else if(x==2)
        {
            scanf("%d",&t); 
            int y = Search(root , t); //search for an element t
            if(y==0) //if y is zero then print not found else print found
            {
                printf("Not Found\n");
            }
            else{
                printf("Found\n");
            }
        }
        else if(x==3)
        {
            InorderTraversal(root); // calling inorder traversal
        }
        else if(x==4)
        {
            PreorderTraversal(root); // calling preorder traversal
        }
        else if(x==5)
        {
            PostorderTraversal(root); // calling postorder traversal
        }
        else if(x==6)
        {
            int z;
            scanf("%d",&z);
            int w = Search(root,z); //first check element is present in bst or not
            if(w==0) //if not then print invalid input else call predecessor function
            {
                printf("Invalid Input\n");
            }
            else{
                Predecessor(root ,pred , z); //predecessor
            }
        }
        else if(x==7)
        {
            int a;
            scanf("%d",&a);
            int b = Search(root,a); //first check element is present in bst or not
            if(b==0) //if not then print invalid input else call successor function
            {
                printf("Invalid Input\n");
            }
            else{
                Successor(root,suc,a);
            }
        }
        else if(x==8)
        {
            exit(1);
        }
    }
}