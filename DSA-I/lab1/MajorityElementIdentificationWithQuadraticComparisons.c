#include<stdio.h>

int main()
{
    int n, fre = 0 , p;
    scanf("%d" , &n);
    int A[n];

    for(int i = 0; i<n; i++ )
    {
        scanf("%d" , &A[i]);
    } 

    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(A[i] == A[j])
            {
                fre++;
                 if(fre>n/2)
                 {
                     p = A[i];
                 }

            }

        }
    }

     if(fre > n/2)
    {
       printf("%d" , p);
     }
     else{
        printf("No Majority\n");
    }

    return 0;
}