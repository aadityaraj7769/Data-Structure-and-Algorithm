#include<stdio.h>

int binary(int *x, int left, int right, int item, int *d)
/* x is  the starting address of the array in which search is to be done
   assumption left <= right
   item searched between indices left and right in the array
   if item is not present , return -1, else--- return value of index where A[posn] is equal to item
*/
{
    int mid;
    
    if(left == right) //array has only one element
    {
        if(x[left] == item){
        return(left);
        }
        else{
            return(-1);
        }
    }
        else{ // array has more than one element
            mid = (left + right)/2;

            if(item==x[mid]){
                return(mid);
            }
            else if((item < x[mid] && left < mid))
            {
                d[0]++;
                return (binary(x, left, mid-1, item, d));
            }
            else if((item > x[mid] && mid < right))
            {
                d[0]++;
                return (binary(x, mid+1, right, item, d));
            }

            else{
                return(-1);
            }
         
        }
    
}

int main()
{
    int n, call, x, i[1];

    scanf("%d" , &n); // enter value of n
    int A[n];

    // taking input of n element
    for(int i = 0; i<n; i++)
    {
        scanf("%d" , &A[i]);
    }

    //value, for which it will searched in array
    scanf("%d" , &x);

    i[0] = 1; // initialize value equal to 1
    call = binary(A, 0, n-1,x, i ); // function call


    // print the output
     printf("%d\n", i[0]);
     printf("%d\n", call);



    return 0;

}