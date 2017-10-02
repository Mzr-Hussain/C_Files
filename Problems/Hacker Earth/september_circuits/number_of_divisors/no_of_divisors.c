#include <stdio.h>
#include <stdlib.h>

#define max 100000						//maxium prime number needed to check is (let) k then, k*k<=max
#define true 1
#define false 0 
int is_prime(int number){
	int *a=(int*)malloc(max*sizeof(int));
	int i,j;
	if(number>=2){
		for(i=0;i<max;i++)
			a[i]=true;
		for(i=2;i*i<=number;i++){
			if(a[i]==true){
				if(number%i!=0){
					for(j=i;j<max;j+=j)
					a[j]=false;
				}
				else{					//exit if not prime
					j=-1;
					break;
				}
			}
			else
			continue;
		}
		if(j==-1)
			return false;
		else
			return true;
	}
	else
		return false;
}

void frst_primes( int x, int array[]){
	int i=0,num=2;
	while( i<x ){
		if(is_prime(num)){
			//printf("%d ",num);
			array[i]=num;
			i++;
		}
		num++;
	}
}

int main(){
	int x;
	long mul = 1, power = 1, result = 1;
	scanf("%d",&x);
	int *prime_at_num = (int*)malloc(x*sizeof(int));
	frst_primes( x, prime_at_num);
	int a[x];
	for(int i=0;i<x;i++){
		scanf("%d",&a[i]);
		power*=(a[i]+1);
		mul*=(a[i]*prime_at_num[i]);
	}
	/*
	printf("\npower = %d\nmul   = %d",power,mul);
	printf("\n");
	for(int i=0;i<x;i++)
		printf("%d ",prime_at_num[i]);
	printf("\n");
	for(int i=0;i<x;i++)
		printf("%d ",a[i]);
	printf("\n");
	//*/
	for(int i=0;i<power/2;i++){
		//result = (result*mul)%1000000007;
		result*=mul;
	}
	printf("%ld",result);
	return 0;
}