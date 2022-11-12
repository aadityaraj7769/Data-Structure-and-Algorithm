#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct reqOutput{
    int v1, v2, cost;
};

struct Data{
    int vert, dist, pred;
};

struct node{
    int item ;
    struct node *next;
};

typedef struct node *nodeptr;
typedef struct Data data ;
typedef struct reqOutput out ;


void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeapify(data A[],int C[], int i, int z)
{
    int left = 2*i+1, right = 2*i+2, small; //initialize left = 2i+1 and right = 2i+2
    if(left > z-1) //if left is greater than total element then return
    {
        return;
    }
    if(A[left].dist < A[i].dist) //if arr[left] < arr[position] then small will be at position left 
    {
        small = left;
    }
    else if(A[left].dist == A[i].dist)
    {
        if(A[left].pred < A[i].pred)
        {
            small = left;
        }else{
            small = i;
        }
    }
    else{ //else position will be small
        small = i;
    }

    if(right <= z-1 ) //if right index is less than total element and arr[right] < arr[small] then small will be right
    {
        if(A[right].dist < A[small].dist)
        {
            small = right;
        }
        else if(A[right].dist == A[small].dist)
        {
            if(A[right].pred < A[small].pred)
            {
                small = right;
            }
        }
    }

    if(small == i) //if both left and right element are greater than the position element(arr[i]) then return
    {
        return;
    }
    else{ //else swap small element and position element(arr[i]) and recursively call minheapify function
        swap(&A[small].vert,&A[i].vert);
        swap(&A[small].dist,&A[i].dist);
        swap(&A[small].pred, &A[i].pred);
        swap(&C[A[small].vert], &C[A[i].vert]);
        MinHeapify(A,C, small,z);
    }
}

void BuildHeap(data A[],int C[], int z)
{
    int index = (z)/2; //assign index will be n/2, because we want to get the first element from last which are not the leaf in heap 
    for(int i = index-1; i>=0;i--)
    {
        MinHeapify(A,C,i,z); 
    }
}

void siftup(data A[],int C[], int u)
{
    int parent = (u-1)/2; //assign parent be (total number of element -1)/2
    while(u>0 && A[u].dist < A[parent].dist) // while his parent is greater then the new element then swap them
    {
        swap(&A[u].vert,&A[parent].vert);
        swap(&A[u].dist,&A[parent].dist);
        swap(&A[u].pred, &A[parent].pred);
        swap(&C[A[u].vert], &C[A[parent].vert]);
        u = parent;
        parent = (u-1)/2;
    }
    return;
}

int main()
{
    int n, j, i, s;
    scanf("%d",&n); //taking input of # of vertices
    int z = n;
    data A[z]; //heap array
    out B[n-1]; //array of size n x 3 which contains required output

    nodeptr arr[n], head[n],tail[n];
    for(int k = 1; k<=n; k++)
    {
        arr[k] = (nodeptr) malloc(sizeof(struct node)); //allocate memory
        arr[k]->item = k; //first node stores the value of that index and next to null
        arr[k]->next = NULL;
        head[k] = tail[k] = arr[k]; //first and last node are same initially
    }

    nodeptr temp0;
    for(int d = 1; d<=n; d++) 
    {
        while(scanf("%d",&j)) //taking input as neighbour of dth vertices , while getting input -1
        {
            if(j == -1)
            {
                break;
            }
            temp0 = (nodeptr) malloc(sizeof(struct node)); //allocate memory and data will be j and next pointer points to null
            temp0->item = j;
            temp0->next = NULL;
            tail[d]->next = temp0; //temp0 will be next of tail
            tail[d] = temp0; //and finally tail will be temp0
        }
        A[d-1].dist = INT_MAX; //Initialize all distance from heap is infinite
        A[d-1].vert = d; //And store vertices corresponding to array index 
        A[d-1].pred = -1; //Initialize all predecessor to -1
        
    }

    scanf("%d",&s); //taking input as starting vertex
    A[s-1].dist = 0; //Initialize its cost to zero

    //At first I made a heap of size n which contains all vertices and as I initialize distance of starting vertex is zero 
    //so after deleting one times and call Minheapify function we have a heap of size n-1 and contains all vertex except starting vertex

    int u, temp = s;
    
    //First go to the neighbour of starting vertex and update its distance and predecessor
    for(int a = 0; a<n; a++)
    {
        if(head[temp]->next == NULL )
        {
            break;
        }
        u = head[temp]->next->item; //here u is neighbour of temp
        head[temp] = head[temp]->next; 
        A[u-1].dist = head[temp]->next->item;
        A[u-1].pred = temp;
        
        head[temp] = head[temp]->next;
    }

    //Creating two array of size n+1 --C[n+1] -> it contains the heap index according to the vertex number
    //flag[n+1] -> it holds the flag of vertices according to its index , 
    int C[n+1], flag[n+1];
    C[0] = -1; flag[0] = -1;
    for(int i = 0; i<n+1; i++) 
    {
        C[i+1] = i; 
        flag[i+1] = 0;
    }
    
    //Build heap with size n
    BuildHeap(A, C, z);

    int x = 0;
    B[x].v1 = A[0].vert; //A[0].vert is the starting vertex
    flag[B[x].v1] = 1; //Mark its flag to 1

    swap(&C[A[0].vert],&C[A[z-1].vert]); //swap heap index from 1 and last element in heap
    
    //Extract minimum
    A[0].vert = A[z-1].vert;
    A[0].dist = A[z-1].dist;
    A[0].pred = A[z-1].pred;
    z--;

    MinHeapify(A,C,0,z);

    //while heap is non empty
    while(z != 0)
    {
        //Update value of array B at index x
        B[x].v1 = A[0].pred; 
        B[x].v2 = A[0].vert;
        B[x].cost = A[0].dist;
        
        flag[B[x].v2] = 1; //mark its flag to 1

        swap(&C[A[0].vert],&C[A[z-1].vert]); //swap heap index from 1 and last element in heap

        //Extract minimum
        A[0].vert = A[z-1].vert;
        A[0].dist = A[z-1].dist;
        A[0].pred = A[z-1].pred;
        z--;

        MinHeapify(A,C,0,z);

        for(int a = 0; a<n; a++)
        {
            if(head[B[x].v2]->next == NULL )
            {
                break;
            }
            u = head[B[x].v2]->next->item; //here u is neighbour of B[x].v2
            head[B[x].v2] = head[B[x].v2]->next;

            if(flag[u] == 0) //Check if vertices is present in heap
            {
                if(A[C[u]].dist > head[B[x].v2]->next->item)
                {
                    A[C[u]].dist = head[B[x].v2]->next->item; //Update its distance/cost
                    A[C[u]].pred = B[x].v2;
                    siftup(A, C, C[u]); //Calling siftup function
                }
            }
            head[B[x].v2] = head[B[x].v2]->next;
        }
        x++;
    }

    //Print the required output
    for(int i = 0; i<n-1; i++)
    {
        printf("%d %d %d\n", B[i].v1, B[i].v2, B[i].cost);
    }

    return 0;
}