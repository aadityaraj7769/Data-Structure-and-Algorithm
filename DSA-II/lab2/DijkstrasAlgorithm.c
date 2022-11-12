#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//heap node contain vertices and distance from source
struct Data{
    int vert;
    int dist;
};

struct node{
    int item ;
    struct node *next;
};

typedef struct node *nodeptr;
typedef struct Data data ;

//swap function
void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Minheapify function
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
    else{ //else position will be small
        small = i;
    }

    if(right <= z-1 && A[right].dist < A[small].dist) //if right index is less than total element and arr[right] < arr[small] then small will be right
    {
        small = right;
    }

    if(small == i) //if both left and right element are greater than the position element(arr[i]) then return
    {
        return;
    }
    else{ //else swap small element and position element(arr[i]) and recursively call minheapify function
        swap(&A[small].vert,&A[i].vert);
        swap(&A[small].dist,&A[i].dist);
        swap(&C[A[small].vert], &C[A[i].vert]);
        MinHeapify(A,C, small,z);
    }
}

void build_heap(data A[],int C[], int z)
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
    while(u>0 && A[u].dist <= A[parent].dist) // while his parent is greater then the new element then swap them
    {
        swap(&A[u].vert,&A[parent].vert);
        swap(&A[u].dist,&A[parent].dist);
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
    }

    scanf("%d",&s); //taking source vertex as input and initialize its distance in heap is zero
    A[s-1].dist = 0;

    //Here store[n] store the predecessor and C[n+1] store the heap index and count = n which I used to run loop n times, and B[n] is 
    int store[n], C[n+1], count = n,  u, B[n];  //used for checking element in S complement(according to lecture discussed in class)
    C[0] = -1; 
    //taking values in C according to vertex number
    for(int i = 0; i<n+1; i++)
    {
        C[i+1] = i;
    }

    //Build heap
    build_heap(A,C,z);

    //D[n] which store the current distance of vertex from source according to its index
    int D[n];

    //Initializing some values
    for(int i = 0; i<n; i++)
    {
        B[i] = 0;
        store[i] = -1;
        D[i] = INT_MAX;
    }

    //predecessor of source vertex is -1 and distance is zero
    store[s-1] = -1;
    D[s-1] = 0;

    //Running loop n times
    while(count != 0)
    {
        int temp = A[0].vert; //store top vertices in heap in temp variable
        B[temp-1] = temp; //B store vertices according to its index 
        count--;
        if(A[0].dist != INT_MAX)
        {
            //Extract minimum
            swap(&C[temp],&C[A[z-1].vert]); //swap heap index from 1 and last element in heap
            A[0].vert = A[z-1].vert;
            A[0].dist = A[z-1].dist;
            z--; 
        
            MinHeapify(A,C,0,z);

            for(int a = 1; a<=n; a++) //loop run n times but if in between the list ended then break the loop
            {
                if(head[temp]->next == NULL )
                {
                    break;
                }
                u = head[temp]->next->item; //here u is neighbour of temp
                head[temp] = head[temp]->next; 
                if(B[u-1] != u)  
                {
                    if(D[temp-1] + head[temp]->next->item < D[u-1]) //edge relaxtation
                    {
                        D[u-1] = D[temp-1] + head[temp]->next->item; //Decrease key
                        A[C[u]].dist = D[temp-1] + head[temp]->next->item; //Decrease key
                        siftup(A,C,C[u]); //Siftup function 
                        store[u-1] = temp; //predecessor of u is temp
                    }
                }
                head[temp] = head[temp]->next;
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        if(D[i] == INT_MAX)
        {
            printf("Unreachable\n");
            continue;
        }
        if(i != s-1 && store[i] == -1)
        {
            printf("Unreachable\n");
            continue;
        }
        
        printf("%d %d\n",D[i],store[i]);
    }
    return 0;
}
