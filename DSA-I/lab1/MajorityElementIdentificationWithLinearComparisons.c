#include<stdio.h>

int main()
{
    int fre = 0, cur_can,  n, c=0;
   
    scanf("%d", &n);
    int A[n];

    for(int i = 0; i<n; i++)
    {
        
        scanf("%d" , &A[i]);
    }

    for(int i = 0; i<n; i++)
    {
       if(fre == 0)
       {
           fre = 1;
           cur_can = A[i];
       }

       else if(A[i] == cur_can)
       {
           fre++;
       }

       else{
           fre--;
       }
    }

    for(int i = 0; i<n; i++)
    {
        if(A[i] == cur_can)
        c++;
    }
    if(c > n/2){
         printf("%d\n" , cur_can );
    }
    else{
        printf("No Majority\n");
    }
    
    return 0;
}