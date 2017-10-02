#include <stdio.h>

int mat[10]={6,2,5,5,4,5,6,3,7,6};


int cal_val(int);



int main()
{

	int a[100000],t,n,i,val[100000],var_least,min;

	scanf("%d",&t);

	while(t--){

		scanf("%d",&n);
		for(i=0;i<n;i++){

			scanf("%d",&a[i]);
			val[i]=cal_val(a[i]);

		}

		for(i=0;i<n;i++){
			printf("%d ",val[i]);
		}
		min=val[0];

		for(i=1;i<n;i++)
	min= min < val[i] ? min : val[i];
		i=0;
		while(min!=val[i])	i++;

		printf("%d\n",a[i]);

	}

	return 0;

}



int cal_val(int a){

	int val=0;
	while(a/10){

		val=val+mat[a%10];

		a=a/10;
	}

	val=val+mat[a%10];
	return val;

}
