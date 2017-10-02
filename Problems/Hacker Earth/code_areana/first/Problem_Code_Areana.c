#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *a;

void print_val(int n, int x){
	int i,sum=0;
	for(i=0;i<n;i++){
		if(a[i]>x)
			sum+=(a[i]/x);
		else if(a[i]==x)
			sum++;
	}
	printf("%d\n",sum);
}

int main(){
	clock_t start_t, end_t, total_t;
	int n,q,i,l,x,y;
	start_t = clock();
	printf("Starting of the program = %ld\n", start_t);
	scanf("%d %d",&n,&q);
	a = (int*)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(q--){
		scanf("%d",&l);
		if(l==1){
			scanf("%d %d",&x,&y);
			a[x-1]=y;
		}
		else{
			scanf("%d",&x);
			print_val(n,x);
		}
	}
	end_t = clock();
	printf("End of the program = %ld\n", end_t);
	return 0;
}
