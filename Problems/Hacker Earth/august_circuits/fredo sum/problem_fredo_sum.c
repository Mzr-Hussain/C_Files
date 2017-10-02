#include<stdio.h>
#include <stdlib.h>

/*							function prototypes
void swap(long*,long*);
int partition(long,int,int);
void quickSort(long,int,int);
void printArray(long,int);
*/

void swap(long* a, long* b){
    long z = *a;
    *a = *b;
    *b = z;
}

int partition (long arr[], int low, int high){
    long pivot = arr[high];
    int j,i = (low - 1);
    for (j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(long arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
//Function to print an array
void printArray(long arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

 
// Driver program to test above functions
int main(){
	int t,n,k;
	scanf("%d",&t);
	while(t>0){
		scanf("%d",&n);
    	long arr[n];
    	for(k=0;k<n;k++)
    	scanf("%ld",&arr[k]);
    	//int n1 = sizeof(arr)/sizeof(arr[0]);
	    //printf("\n%d\n%d\n",n1,n);
		quickSort(arr, 0, n-1);
    	//printArray(arr,n);
		long minsum=0,maxsum=0;
    	for(k=0;k<n;k+=2)
	    	minsum+=arr[k+1]-arr[k];
    	for(k=0;k<n/2;k++)
	    	maxsum+=arr[n-k-1]-arr[k];
		
		printf("%ld %ld\n",minsum,maxsum);
    	t--;
	}
    return 0;
}
