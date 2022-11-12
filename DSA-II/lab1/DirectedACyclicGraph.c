#include<stdio.h>
#include<stdlib.h>
  
struct node{
    int data ;
    struct node *next;
};

struct vertices{
    int visit;
    int entry;
    int exits;
    int predecessor;
};

typedef struct node *nodeptr;
typedef struct vertices vert;
nodeptr top;
int clock = 0, count = 0; 
int n,u;
int q = 1;

void push(int v)
{
    nodeptr temp; //create new node temp and allocate memory
    temp = (nodeptr)malloc(sizeof(struct node));
    //Check if stack is full than inserting an element would lead to stack overflow
    if(!temp)
    {
        exit(1);
    }
    else
    {
        temp->data = v; //initialize temp data be v
        temp->next = top; //and temp->next stores the address of top
        top = temp; //and finally top be temp
    }
}
void DFSexplore(nodeptr arr[], int v, vert A[]) //DFS explore function  
{
    
    A[v].visit = 1; //Marked that vertices visited
    A[v].entry = clock; //Entry time of vertices be clock
    
    clock++; //Increase clock by 1

    for(int a = 1; a<=n; a++) //loop run n times but if in between the list ended then break the loop
    {
        if(arr[v]->next == NULL)
        {
            break;
        }
        u = arr[v]->next->data; //assign u be the next data and if visit of u be zero then call Dfsexplore function with index u 
        if(A[u].visit == 0)
        {
            A[u].predecessor = v; //Predecessor of u is v
            DFSexplore(arr, u , A); //call recursively dfsexplore function , but vertices will be u
        }
        arr[v] = arr[v]->next;
    }

    A[v].exits = clock; //Exit time of vertices v
    push(v); //pushing vertices into the stack
    clock++;
}

int num = 1;
void DFS(nodeptr arr[], int v, vert A[])
{
    while(num <= n) //loop runs n times
    { 
        if(A[num].visit == 0) //and if any vertices not visited then call Dfsexplorefunction
        {
            DFSexplore(arr , num, A);
        }
        num++;
    }
}

//Printing entry time, exit time, and predecessor of all vertices from 1-n 
void entryexitpred(nodeptr arr[], vert A[])
{
    for(int i = 1; i<=n; i++)
    {
        printf("%d %d %d\n", A[i].entry, A[i].exits, A[i].predecessor);
    }
}

void backedge(nodeptr arr[], vert A[])
{
    //In a graph, if there is an edge between u and v and entry(v) < entry(u) < exit(u) < exit(v) than that edge will be backedge 
    for(int a = 1; a<=n; a++) 
    {
        while(arr[a]->next != NULL) //as per the given constraints in question, i am checking as per the input order of the neighbour list and increasing order of vertex numberse
        {
            int s = arr[a]->next->data;
            if(A[s].entry < A[a].entry &&  A[a].exits < A[s].exits)
            {
                if(count == 0) //this condition, because i want to print "Not a DAG" only once
                {
                    printf("Not a DAG\n");
                }
                printf("%d %d %d %d\n",A[s].entry, A[a].entry,A[a].exits,A[s].exits);
                count++;
            }
            arr[a] = arr[a]->next;
        }
    }
}

//print the vertices in topological order
void topological()
{
    nodeptr temp; //create new node temp
        temp = top; //else assign temp to tops
        while(temp != NULL) //While temp is not equal to null , print the vertices
        {
            printf("%d\n",(*temp).data);
            temp = temp->next; 
        }
}

int main()
{
    int  i , j, m, start;
    
    scanf("%d",&n); //taking number of vertices

    vert A[n]; 

    nodeptr arr[n], head[n],tail[n];
    for(int k = 1; k<=n; k++)
    {
        arr[k] = (nodeptr) malloc(sizeof(struct node)); //allocate memory
        arr[k]->data = k; //first node stores the value of that index and next to null
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
        temp0->data = j;
        temp0->next = NULL;
        tail[d]->next = temp0; //temp0 will be next of tail
        tail[d] = temp0; //and finally tail will be temp0
        }
        
        A[d].entry = -1;
        A[d].exits = -1;
        A[d].predecessor = -1;
        A[d].visit = 0;
    }

    

    scanf("%d",&start); //starting index in dfs

    DFSexplore(arr,start, A); //Calling dfsexplore function

    DFS(arr,start,A); //Calling dfs function

    entryexitpred(head,A); //Calling entryexitpred function

    backedge(head,A); //Calling backedge function

    if(count == 0) // If there will not be any backedge in graph then print "DAG" and topological function
    {
        printf("DAG\n");
        topological();
    }

    return 0;
}