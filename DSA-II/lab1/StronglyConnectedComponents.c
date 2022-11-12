#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int data ;
    struct node *next;
};

//All items related to vertices inside struct
struct vertices{
    int visit;
    int entry;
    int exit;
    int predecessor;
};

typedef struct node *nodeptr;
typedef struct vertices vert;
nodeptr top;
int clock = 0, count = 0; 
int n,u;

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
        temp->data = v; //initialize temp item be n
        temp->next = top; //and temp->next stores the address of tops
        top = temp; //and finally tops be temp
    }
}

void DFSexplore(nodeptr arr[], int v, vert A[]) //DFS explore function
{
    A[v].visit = 1; //Marked that vertices visited
    A[v].entry = clock; //Entry time of vertices be clock
    clock++;
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
    A[v].exit = clock; //Exit time of vertices v
    push(v); //push into stack
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

//After computing reverse graph , print the outneighbour vertices
void printreversearray(nodeptr brr[])
{
    for(int i = 1; i<=n; i++) //for vertices from 1 to n, print the outneighbour of that vertices
    {
        if(brr[i]->next == NULL ) //for ending of one vertices print -1 at last 
        {
            printf("-1\n");
        }
        else{
            while(brr[i]->next != NULL)
            {
                printf("%d",brr[i]->next->data);
                brr[i] = brr[i]->next;
                if(brr[i]->next != NULL)
                {
                    printf(" ");
                }else{
                    printf(" -1\n");
                }
            }
        }
    }
}

// here i am storing vertices in topological order in topo array
void topol(nodeptr arr[], int topo[])
{
    int i = 0;
    nodeptr temp;
    temp = top; //else assign temp to top
    while(temp != NULL) //While temp is not equal to null , topo[i] = temp->data 
    {
        topo[i] = temp->data;
        i++;
        temp = temp->next; 
    }
}

void dfsexplore(nodeptr brr[], int v, vert B[])
{
    B[v].visit = 1; //Marked that vertices visited
    printf("%d",v); //print that vertex
    count++;
    for(int j = 1; j<=n; j++) //loop run n times but if in between the list ended then break the loop
    {
        if(brr[v]->next == NULL)
        {
            break;
        }
        u = brr[v]->next->data; //assign u be the next data and if visit of u be zero then call Dfsexplore function with index u 
        if(B[u].visit == 0)
        {
            printf(" ");
            B[u].predecessor = v;
            dfsexplore(brr, u , B);
        }
        brr[v] = brr[v]->next;
    }
}

int main()
{
    int  i , j, m, start;
    scanf("%d",&n); //taking number of vertices
    int topo[n];
    vert A[n], B[n];

    //Here I am creating 2 linked list - one for input graph and another for reverse graph
    nodeptr arr[n], head[n],tail[n], brr[n], headr[n],tailr[n];
    for(int k = 1; k<=n; k++)
    {
        arr[k] = (nodeptr) malloc(sizeof(struct node)); //allocate memory
        arr[k]->data = k; //first node stores the value of that index and next to null
        arr[k]->next = NULL;
        head[k] = tail[k] = arr[k]; //first and last node are same initially

        brr[k] = (nodeptr) malloc(sizeof(struct node)); //allocate memory
        brr[k]->data = k; //first node stores the value of that index and next to null
        brr[k]->next = NULL;
        headr[k] = tailr[k] = brr[k]; //first and last node are same initially
    }

    //Adding the neighbour vertices in linked list
    nodeptr temp0;
    for(int d = 1; d<=n; d++) // users taking input , number of edges of i and j are the edges between them
    {
        while(scanf("%d",&j))
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
        A[d].exit = -1;
        A[d].predecessor = -1;
        A[d].visit = 0;

        B[d].entry = -1;
        B[d].exit = -1;
        B[d].predecessor = -1;
        B[d].visit = 0;
        
    }

    //Computing reverse graph---if (1)->2->5 i.e, outneighbours of 1 is 2 and 5 then in reverse graph 
    //outneighbour of 2 and 5 is 1
    nodeptr tem;
    for(int g = 1; g<=n; g++)
    {
        while(arr[g]->next != NULL)
        {
            tem = (nodeptr) malloc(sizeof(struct node));
            tem->data = g; //here suppose g is 1 and suppose arr[g]->next->data is 2 then tailr[2]->next is temp 
            tem->next = NULL;
            tailr[arr[g]->next->data]->next = tem;
            tailr[arr[g]->next->data] = tem;
            arr[g] = arr[g]->next;
        }
    }

    scanf("%d",&start); //starting index in dfs

    DFSexplore(head,start, A);
    
    DFS(head,start,A);

    printreversearray(headr);

    topol(head,topo);

    //After arranging in topological order , we do dfs from starting in reverse graph
    //After returning in one dfsexplore function, we get the strongly connected components
    for(int h = 1; h<=n; h++)
    {
        if(B[topo[h-1]].visit == 0)
        {
            dfsexplore(brr,topo[h-1], B); //I made another dfsexplore function because I am printing only strongly
                                                //connected components in that function
            if(count != n)
            {
            printf("\n");
            }
        }
    }
    return 0;
}