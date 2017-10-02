#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 	int j;
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)	
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Solve (int* arr , int n) {
   // write code here
   int k;
   for(k=0;k<n;k++)
	   printf("%d ",arr[k]);
   printf("\n");
   int j=0,i=1;
   while(i<n){
	   if(arr[i]==arr[i-1]){
		   arr[i]=arr[i]-2;
	   }
	   i++;
   }
   quickSort(arr, 0, n-1);
   for(k=0;k<n;k++)
	   printf("%d ",arr[k]);
   printf("\n");
   for(i=2; i<arr[n-1] ; i=i+2){
        for(;arr[j]!=i && j<n ; j++);
        if(j==n && arr[j]!=i)
            goto end;
        if(j==n && arr[j]==i){
            i=i+2;
            goto end;
        }
   }
   end:   return i;
}

int main() {
    int T;
    scanf("%d", &T);
    int t_i;
	for(t_i=0; t_i<T; t_i++)
    {
        int n;
        scanf("%d", &n);
        int i_arr;
        int *arr = (int *)malloc(sizeof(int));
        for(i_arr=0; i_arr<n; i_arr++){
        	scanf("%d", &arr[i_arr]);
        	if(arr[i_arr]&1)
        	    arr[i_arr]--;
        }

        int out_ = Solve(arr,n);
        printf("%d", out_);
        printf("\n");
    }
}
