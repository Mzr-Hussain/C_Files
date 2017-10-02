#include <stdio.h>
#include <stdlib.h>
#define max 100000
int interpolationSearch(int arr[], int n, int x){
    int lo = 1, hi = (n - 1);
//	printf("quire[%d]=%d quire[%d]=%d x=%d\n ",lo,arr[lo],hi,arr[hi],x);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]){
		int pos = lo + (((double)(hi-lo) /
              (arr[hi]-arr[lo]))*(x - arr[lo]));
        if (arr[pos] == x){
            return pos;
		}
        if (arr[pos] < x)
            lo = pos + 1;
		else
            hi = pos - 1;
//		printf("quire[%d]=%d quire[%d]=%d quire[%d]=%d x=%d\n ",lo,arr[lo],pos,arr[pos],hi,arr[hi],x);
	}
    return -1;
}

int main()
{
    int n,Que,q;
    scanf("%d",&n);
    int a[n],end;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&Que);
    while(Que--){
        int sum=0;
        int *quire=calloc(max,sizeof(int));
        scanf("%d",&q);
        for( end=1 ; q*end<max ; end++ ){
            quire[end]=q*end;
		}
        for(int i=0;i<n;i++){
            q=interpolationSearch(quire , end-1, a[i]);
//			printf("%d\n",q);
            if(q!=-1)
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
