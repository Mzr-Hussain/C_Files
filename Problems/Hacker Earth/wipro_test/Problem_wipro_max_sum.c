#include<stdio.h>
int main(){
	int t,j,i=1,sum;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&i);
		i=((i&1)?i:i-1);
		sum=0;
		for(j=1;j<=i;j++){
			if(j&1)
				sum=sum+(j*(j+1));
			else
				sum=sum-(j*(j+1));
		}
	printf("%d\n",sum);
	}
	return 0;
}
