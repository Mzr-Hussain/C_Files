#include<stdio.h>
int main(){
	int n,i,j,sum;
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==0){
				if(j==0){
					if(prime(a[0][1]+a[1][0]))
					sum=sum+1;
				}
				else if(j==n-1){
					if(prime(a[0][n-2]+a[1][n-1]))
					sum=sum+1;
				}
				else{
					if(prime(a[0][j+1]+a[1][j]+a[0][j-1]))
					sum=sum+1;
				}	
			}
			else if(i==n-1){
				if(j==0){
					if(prime(a[n-1][1]+a[n-2][0]))
					sum=sum+1;
				}
				else if(j==n-1){
					if(prime(a[n-1][n-2]+a[n-2][n-1]))
					sum=sum+1;
				}
				else{
					if(prime(a[n-1][j+1]+a[n-2][j]+a[n-1][j-1]))
					sum=sum+1;
				}
			}
			else{
				if(j==0){
					if(prime(a[i+1][0]+a[i][1]+a[i-1][0]))
					sum=sum+1;
				}
				else if(j==n-1){
					if(prime(a[i+1][n-1]+a[i][n-2]+a[i-1][n-1]))
					sum=sum+1;
				}
				else{
					if(prime(a[i-1][j]+a[i][j+1]+a[i+1][j]+a[i][j-1]))
					sum=sum+1;
				}
			}
		}
	}
	printf("%d",sum);
}