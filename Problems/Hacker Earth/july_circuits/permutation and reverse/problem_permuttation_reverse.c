#include<stdio.h>
int n_global,count=0;
int lens[200]={0};

/* A utility function to print an array of size n 
void printArray(int arr[], int n)
{
	int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
		printf("\n");
}*/

/* Reverses arr[0..i] and chane global array variable lens to i+1*/
void flip(int arr[], int i)
{
    lens[count]=i+1;
    count++;
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}
 
/* Returns index of the maximum element in arr[0..n-1] */
int findMax(int arr[], int n)
{
   int mi, i;
   for (mi = 0, i = 0; i < n; ++i)
       if (arr[i] > arr[mi])
              mi = i;
   return mi;
}
 
// The main function that sorts given array using flip 
// operations
int pancakeSort(int *arr, int n)
{
	int curr_size;
    // Start from the complete array and one by one reduce
    // current size by one
    for (curr_size = n; curr_size > 1; --curr_size)
    {
        // Find index of the maximum element in 
        // arr[0..curr_size-1]
        int mi = findMax(arr, curr_size);
 
        // Move the maximum element to end of current array
        // if it's not already at the end
        
		if (mi != curr_size-1)
        {
            if(mi==0){
            	// Now move the maximum number to end by reversing
            	// current array
            	flip(arr, curr_size-1);
            }
            else{
            	// To move at the end, first move maximum number
            	// to beginning 
            	flip(arr, mi);
 
 	            // Now move the maximum number to end by reversing
    	        // current array
        	    flip(arr, curr_size-1);
            }
        }
    }
}
 
int main(){
	int i,x,n;
	scanf("%d",&n);
	int arr[n],a[n],b[n+n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	n_global=n;
	for(i=0;i<n;i++)
	b[i]=b[n+i]=a[i];
	//sort_with(arr,b);							---- this line iplements modefied code to be written
    pancakeSort(arr,n);
	
	printf("%d\n",count);
    for(i=0;i<count;i++) printf("1 %d\n",lens[i]);
    
	return 0;
}

/*sort_with(int *arr,int s){
	int n_local=n_global;
	while(n_local>0){
		//modefied code here
	}
}*/