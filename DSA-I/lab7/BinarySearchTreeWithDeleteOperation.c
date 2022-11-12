#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left, *right, *parent;
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
    temp->parent = NULL;
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
            temp->parent = prev;
        }
        else{
            prev->right = temp;
            temp->parent = prev;
        }
    }
}

nodeptr Search(nodeptr root , int t)
{
    
    if(root == NULL) //if bst has no element then return NULL
    {
       
         return NULL;
    }
    else{
        if(t == root->key) //if key value is equal to root key value then return root
        {
            
             return root;
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

nodeptr Predecessor(nodeptr root ,nodeptr pred, int z)
{
    nodeptr tem = NULL;
    if(root == NULL)
    {
        return tem;
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
    return tem;
    
    
}

nodeptr Successor(nodeptr root, nodeptr suc,int c)
{
    nodeptr tem0 = NULL;
    if(root == NULL)
    {
        return tem0;
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
    return tem0;
}

void Deletion(nodeptr del)
{
    nodeptr temp;
    temp = del;
    if(del->left == NULL && del->right == NULL && del->parent == NULL) //if there are only one element
    {
        root = NULL; //then root be null
    }
    else if(del->left == NULL && del->right == NULL && del->parent != NULL) // if there are no children
    {
        if(del->parent->left ==del) // and del will be the left children
        {
            del->parent->left = NULL; 
            del->parent = NULL;
            free(temp);
        }
        else{ //and when del be the right children
            del->parent->right = NULL;
            del->parent = NULL;
            free(temp);
        }
    }
    else if(del->left == NULL && del->parent != NULL) //if only the left subtree be null
    {
        if(del->parent->left == del) // and del will be the left children
        {
            del->parent->left = del->right;
            del->right->parent = del->parent;
            free(temp);
        }
        else{ //and when del be the right children
            del->parent->right = del->right;
            del->right->parent = del->parent;
            free(temp);
        }
    }
    else if(del->right == NULL && del->parent != NULL) //if only the right subtree be null
    {
        if(del->parent->left == del) // and del will be the left children
        {
            del->parent->left = del->left;    
            del->left->parent = del->parent;       
            free(temp);
        }        
        else{ //and when del be the right children
            del->parent->right = del->left;
            del->left->parent = del->parent;
            free(temp);
        }
    }
    else if(del->parent == NULL && (del->left != NULL) && (del->right == NULL)) //If right subtree and parent is null
    {
        del->left->parent = NULL;
        root = del->left;
        del->left = NULL;
        
        free(temp);
    }
    else if(del->parent == NULL && (del->right != NULL) && (del->left == NULL)) //If left subtree and parent is null
    {
        del->right->parent = NULL;
        root = del->right;
        del->right = NULL;
        free(temp);
    }
    else if(del->right != NULL && del->left != NULL) //if both subtree are not null
    {
        nodeptr pred = NULL;
        nodeptr x = Predecessor(root,pred,del->key); // node x be the predecessor of del
        del->key = x->key; //and copy the data of x in del 
        Deletion(x); //and finally delete x(successor of del)
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
            nodeptr y = Search(root , t); //search for an element t and return node containing t
            if(y==NULL) //if y is NULL then print not found else print found
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
            nodeptr w = Search(root,z); //first check element is present in bst or not
            if(w==NULL) //if not then print invalid input else call predecessor function
            {
                printf("Invalid Input\n");
            }
            else{
                nodeptr p = Predecessor(root ,pred , z); //predecessor
                if(p == NULL)
                {
                    printf("No predecessor\n");
                }
                else{
                    printf("%d\n",p->key);
                }
            }
        }
        else if(x==7)
        {
            int a;
            scanf("%d",&a);
            nodeptr b = Search(root,a); //first check element is present in bst or not
            if(b==NULL) //if not then print invalid input else call successor function
            {
                printf("Invalid Input\n");
            }
            else{
                nodeptr t = Successor(root,suc,a);
                if(t == NULL) //if x be NULL then print No successor else print the successor key
                {
                    printf("No successor\n");
                }
                else{
                    printf("%d\n",t->key);
                }
            }
        }
        else if(x==8)
        {
            int num;
            scanf("%d", &num);
            nodeptr k = Search(root,num); //k be the node which we want to delete
            if(k==NULL) //if k is NULL then print invalid input else call Delete function
            {
                printf("Deletion Fail\n");
            }
            else{
                Deletion(k);
            }
        }

        else if(x==9)
        {
            exit(1);
        }
    }
    return 0;
}