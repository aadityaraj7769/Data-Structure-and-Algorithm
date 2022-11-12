#include<stdio.h>
#include<stdlib.h>

//Creating struct node
struct node{
    int key, rank;
    struct node *parent;
};

int n;
typedef struct node *nodeptr;

void makeSet(nodeptr A[])
{
    //assign all items at zeroth index to be default values 
    A[0] = (nodeptr)malloc(sizeof(struct node)); //allocate memory
    A[0]->key = -1;
    A[0]->rank = -1;
    A[0]->parent = NULL;

    //assign at all index except at zeroth index , at index i -> its key value is i and its rank is initially zero and parent to itself
    for(int i = 1; i<n+1; i++)
    {
        A[i] = (nodeptr)malloc(sizeof(struct node));
        A[i]->key = i;
        A[i]->rank = 0;
        A[i]->parent = A[i];
    }
}

int find(nodeptr A[], int x)
{
    int y = x;
    //finding the root node key value in a subset containing element x
    while(A[y]->parent->key != y)
    {
        y = A[y]->parent->key;
    }

    //all node in the path of finding root node , assign that all node parent to root node
    int z = x, p;
    while(A[z]->parent->key != z)
    {
        p = A[z]->parent->key;
        A[z]->parent = A[y];
        z = p;
    }
    return y;
}

void Union(nodeptr A[], int a, int b)
{
    //p1/p2 is the representative/root node key value of subset containing a/b
    int p1 = find(A,a);
    int p2 = find(A,b);

    //if p1 and p2 both are present in same subset then simply print its value and rank
    if(p1 == p2)
    {
        printf("%d %d\n", p1, A[p1]->rank);
    }

    //if p1 != p2
    else{
        //r1 and r2 is the rank of p1 and p2 respectively
        int r1 = A[p1]->rank;
        int r2 = A[p2]->rank;

        //if both rank are equal then anyone of the parent is the other and increase its rank by 1
        if(r1 == r2)
        {
            A[p2]->parent = A[p1];
            A[p1]->rank++;
            printf("%d %d\n", p1, A[p1]->rank);
        }
        //if rank1 < rank2 then parent(p1) = p2
        else if(r1 < r2)
        {
            A[p1]->parent = A[p2];
            printf("%d %d\n", p2, A[p2]->rank);
        }
        //If rank1 > rank2 then parent(p2) = p1
        else{
            A[p2]->parent = A[p1];
            printf("%d %d\n", p1, A[p1]->rank);
        }
    }
}

void print(nodeptr A[])
{
    for(int i = 1; i<n+1; i++)
    {
        int f =  find(A,A[i]->key); //Representative value of all key values
        printf("%d %d\n", i, f );
    }
}

int main()
{
    scanf("%d",&n); //taking input of number of elements

    //Creating a nodeptr array of size n+1
    nodeptr A[n+1];
    //calling makeset operation
    makeSet(A);

    int t, f;
    while(1)
    {
        scanf("%d",&t);

        if(t == 1)
        {
            int x; //element x is to find
            scanf("%d",&x);
            f = find(A,x); //call find function
            printf("%d\n",f);
        }
        else if(t == 2)
        {
            int a, b;
            scanf("%d %d", &a, &b);

            //union of elements a and b 
            Union(A, a, b);
        }
        else if(t == 3)
        {
            //print all element with its representative values which is its parent values(because reordering in find function)
            print(A);
        }
        else if(t == 4)
        {
            exit(0);
        }
    }
    return 0;
}