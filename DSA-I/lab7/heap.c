#include<stdio.h>
#include<stdlib.h>


void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeapify(int arr[], int i, int n)
{
    int left = 2*i+1, right = 2*i+2, small; //initialize left = 2i+1 and right = 2i+2
    if(left > n-1) //if left is greater than total element then return
    {
        return;
    }
    if(arr[left] < arr[i]) //if arr[left] < arr[position] then small will be at position left 
    {
        small = left;
    }
    else{ //else position will be small
        small = i;
    }

    if(right <= n-1 && arr[right] < arr[small]) //if right index is less than total element and arr[right] < arr[small] then small will be right
    {
        small = right;
    }

    if(small == i) //if both left and right element are greater than the position element(arr[i]) then return
    {
        return;
    }
    else{ //else swap small element and position element(arr[i]) and recursively call minheapify function
        swap(&arr[small],&arr[i]);
        MinHeapify(arr, small,n);
    }
}

void build(int arr[], int n)
{
    int index = (n)/2; //assign index will be n/2, because we want to get the first element from last which are not the leaf in heap 
    for(int i = index-1; i>=0;i--)
    {
        MinHeapify(arr,i, n); 
    }
}

void Siftup(int arr[], int i)
{
    int parent = (i-1)/2; //assign parent be (total number of element -1)/2
    while(i>0 && arr[i] <= arr[parent]) // while his parent is greater then the new element then swap them
    {
        swap(&arr[i],&arr[parent]);
        i = parent;
        return;
    }
}

void Heap(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d\n",arr[i]);
    }
}

void Decreasekey(int arr[], int i, int nv, int n)
{
    if((arr[i] < nv) || i>n-1) //if position element < new value or position index is greater then the largest index then print operation fail
    {
        printf("Operation Fail\n");
    }
    else{ //else position element = new value and call siftup function
        arr[i] = nv;
        Siftup(arr, i );
    }

}
int main()
{
    int n, A[100];
    scanf("%d",&n); //n be the total number of elements
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&A[i]); // taking n element from users
    }
    build(A, n); //calling build function
    int x;
    while(scanf("%d", &x) != EOF) //here , scanf returns a value so if we don't give any value then this will simply exit from program
    {
        //Insert new element
        if(x==1)
        {
            int num;
            scanf("%d",&num); //input for inserting new element
            n++; //increase the size of array
            if(n>100)
            {
                printf("Operation Fail\n");
            }
            else{
                A[n-1] = num; //first this will insert at last position then call siftup function
                Siftup(A, n-1);
            }
        }
        else if(x==2)
        {
            //Delete the element of given indices
            int ind;
            scanf("%d",&ind);
            if(ind > n-1)
            {
                printf("Operation Fail\n");
            }
            else{ 
                A[ind] = A[n-1]; //A[ind] will be equal to last element
                n--;               // Decrease the size of array and call Minheapify function
                MinHeapify(A, ind , n);
            }
        }
        else if(x==3)
        {
            //Extractmin;
            int temp = A[0]; //temp store the value of root element
            printf("%d\n",temp); //print the first element
            A[0] = A[n-1]; //root element stores the value of last element
            n--; //Decrease the size of array and call minheapify function
            MinHeapify(A,0,n);
            
        }
        else if(x==4)
        {
            Heap(A,n); //calling heap function , this will print the total element of increasing index
        }
        else if(x==5)
        {
            //Decrease key 
            int pos, newval;
            scanf("%d",&pos); //taking input position index and new value and call decreasekey function 
            scanf("%d",&newval);
            Decreasekey(A,pos,newval,n);
        }
        else if(x==6)
        {
            //Find min 
            printf("%d\n",A[0]); //minimum function is present at the root or simply first element of array
        }
        else if(x==7)
        {
            exit(1);
        }
    }
    return 0;
}