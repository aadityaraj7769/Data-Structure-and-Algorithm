#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printNegativeCycle(int a, int b, int B[])
{
    for(int i = b-1; i>a; i--)
    {
        printf("%d ",B[i]);
    }
    printf("%d",B[a]);
}

int main()
{
    int n, m, v1,v2,w;
    scanf("%d %d",&n,&m); //taking input as number of vertices and number of edges

    //Initialize two array, 1-> of size m x 3, when there is an edge between a to b and edge weight c then I store in this array 
    //2-> of size n x 2 , which store distance from source according to vertex number and index and also store predecessor 
    int A[m][3], D[n][2];
    for(int i = 0; i<m; i++)
    {
        scanf("%d %d %d",&v1,&v2,&w); //taking input a b c and store respectively in m x 3 size array
        A[i][0] = v1;
        A[i][1] = v2;
        A[i][2] = w;
    }

    int s;
    scanf("%d",&s);  //taking source vertex input

    //Initialize all distance from source is infinity and predecessor -1
    for(int i = 0; i<n; i++)
    {
        D[i][0] = INT_MAX;
        D[i][1] = -1;
    }

    //Now distance of source is 0
    D[s-1][0] = 0;
    int flag = 0, k, ct = 0;

    //Edge relaxtation n times , if at nth round , any vertex updated then there must be present a negative cycle in graph
    for(int i = 0; i<n; i++)
    {
        flag = 0;
        for(int j = 0; j<m; j++)
        {
            if(D[A[j][0]-1][0] != INT_MAX)
            {
                if(D[A[j][0]-1][0] + A[j][2] < D[A[j][1]-1][0] ) //Edge relaxtation condition
                {
                    D[A[j][1]-1][0] = D[A[j][0]-1][0] + A[j][2];
                    flag = 1;
                    D[A[j][1]-1][1] = A[j][0]; //Storing predecessor

                    if(i == n-1 && ct == 0)
                    {
                        k = A[j][1]; //This is the vertex which got updated earlier at nth round
                        ct++;
                    }
                }
            }
        }
        if(flag == 0)
        {
            break;
        }
    }

    //If there is no negative cycle in the graph then print required output
    if(flag == 0)
    {
        for(int i = 0; i<n; i++)
        {
            if(i != s-1 && D[i][1] == -1)
            {
                printf("Unreachable\n");
                continue;
            }
            printf("%d %d\n",D[i][0],D[i][1]);
        }
    }

    // If there will be a negative cycle in graph 
    else{
        //In array B we store predecessor, like at (i)th position element is the predecessor of (i-1)th element
        int B[n+1], t = 2, l = 0;
        B[0] = k;
        B[1] = D[k-1][1];

        for(int m = 2; m<n+1; m++)
        {
            B[m] = D[B[m-1]-1][1];
        }

        //If there will be negative cycle then in array B, there will must be contain a vertices 2 times 
        for(int a = 0; a<n+1; a++)
        {
            for(int b = 0; b<n+1; b++)
            {
                if(a != b)
                {
                    if(B[a] == B[b]) //After getting same vertices two times , print required output(according to instruction)
                    {
                        printNegativeCycle(a,b,B);
                        exit(0);
                    }
                }
            }
        }
    }
    return 0;
}