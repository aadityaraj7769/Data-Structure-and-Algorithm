#include<stdio.h>

int n;

void printMatrix(int B[][n])
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%d", B[i][j]);
            if(j != n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printPred(int P[][n])
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(P[i][j] == -1)
            {
                printf("NIL");
            }else{
                printf("%d", P[i][j]);
            }
            if(j != n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

void floydWarshall(int A[][n], int P[][n])
{
    int B[n][n], i , j, k, pred[n][n]; // initialize some variable of int type

    //B array contains initially - distance as given input and
    //pred array contains - if i to j is the direct edge then pred of j is i else -1
    for( i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            B[i][j] = A[i][j];
            if(A[i][j] != 55555 && i != j)
            {
                pred[i][j] = i+1;
            }else{
                pred[i][j] = -1;
            }
        }
    }

    //Expanding the set of intermediate vertices
    for(k = 0; k<n; k++)
    {
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
            {
                if(B[i][k] + B[k][j] < B[i][j])
                {
                    B[i][j] = B[i][k] + B[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
        
        //when the subset of {v1, v2} vertices are allowed as an intermediate vertices
        if(k == 1)
        {
            printf("Pairwise Distance Matrix After Two Rounds\n");
            printMatrix(B);
            printf("Pairwise Predecessor Matrix After Two Rounds\n");
            printPred(pred);
        }

        //when the subset of all vertices are allowed as an intermediate vertices
        if(k == n-1)
        {
            printf("Final Pairwise Distance Matrix\n");
            printMatrix(B);
            printf("Final Pairwise Predecessor Matrix\n");
            printPred(pred);
        }
    }
}

int main(){

    scanf("%d",&n); //taking input as number of vertices
    int A[n][n], P[n][n]; //initialize two 2d array of size n x n. one for all pairs shortest path distance and other is for predecessor

    //taking input of ith row of the edge weight matrix
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    floydWarshall(A, P); //calling floydWarshall function
    return 0;
}