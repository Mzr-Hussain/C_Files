#include<stdio.h>
#define found 1
#define unfound 0
int main(){
	int flag=unfound,n=0,s=0,i=0,j=0,k,sum=0,a=0,b=0;
	scanf("%d %d",&n,&s);
	int t[n],d[n];
	for(i=0;i<n;i++)
	scanf("%d %d",&t[i],&d[i]);

/*	
	struct one{
		int index;
		long td;
	}x[n];
	for(i=0;i<n-1;i++){
		x[i].index = i;
		x[i].td = (t[i+1]-t[i])*d[i];
	}
	x[n-1].index = n-1;
	x[n-1].td = -1;
	int n_exp=0,j=0;
	while(j<n){
		for(i=t[j];i<t[j+1];i++)
		n_exp++;
	}
	printf("%d---\n",n_exp+1);
*/
	int cot=-1;
	if(s%d[n-1]!=0) cot=0;
	int cot2=(t[n-1]+1+(s/d[n-1])+cot);
	int expand[cot2];
//	printf("\nstart\n");
	while(j<n-1){
		for(i=t[j];i<t[j+1];i++){
//			printf("i=%d\n",i);
			expand[i]=d[j];
		}		
//		printf("j=%d\n",j);
		j++;
	}
//	printf("\nstart2\n");
	for(i=t[n-1];i<cot2;i++)
	expand[i]=d[n-1];
//	printf("\nstart\n");
//	for(i=0;i<cot2;i++)
//	printf("expand[%d]=%d\n",i,expand[i]);
	for(j=0;(flag==unfound)&&(j<cot2);j++){
		for(i=0;(flag==unfound)&&(i<t[n-1]+1);i++){
			sum=0;
			for(k=i;(flag==unfound)&&(k<=i+j);k++){
				sum=sum+expand[k];
			}
			if(sum==s)
			flag=found;
		}
	}
	a=j,b=i;
	/*if(a%b==0)
	printf("%d/1",(a%b));
	else*/
	printf("%d/%d",a,b);
		
	return 0;
}
