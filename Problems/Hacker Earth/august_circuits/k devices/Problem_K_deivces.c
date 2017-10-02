#include<stdio.h>
#include<math.h>
long rm=1414213563,ri=-1;

long search(long x[],long y[],int n,int k){
	long ra;
	int i,j=0;
	ra=(rm+ri)/2;
	printf("rm=%d\nra=%d\nri=%d\n",rm,ra,ri);
	if(rm==ra)	return ra;
	if(ri==ra)	return ra+1;
	for(i=0;i<n;i++){
		if((int)ceil(sqrt((x[i]*x[i])+(y[i]*y[i]))) <= ra)	j++;
		if(j>=k)	break;
	}
	if(j>=k)		rm=ra;
	else			ri=ra;
	return search(x,y,n,k);
}

int main(){
	int i,n,k;
	long r,*x,*y;
	scanf("%d %d",&n,&k);
	x=(long*)calloc(n,sizeof(long));
	y=(long*)calloc(n,sizeof(long));
	for(i=0;i<n;i++)
		scanf("%ld",&x[i]);
	for(i=0;i<n;i++)
		scanf("%ld",&y[i]);
//	for(i=0;i<n;i++)
//		printf("%d %d",x[i],y[i]);
//	printf("\n");
	r=search(x,y,n,k);
	printf("%ld",r);
	return 0;
}
