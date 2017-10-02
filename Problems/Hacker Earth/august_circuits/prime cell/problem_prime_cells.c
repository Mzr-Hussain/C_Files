#include<stdio.h>
#define true 1
#define false 0 
int	 main(){
	int n,m,i,j,sum=0;
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		//a[i][j]=i+1;
		scanf("%d",&a[i][j]);
	}
	m=n-1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((i==0)&&(j==0)){
				if(is_prime(a[0][1]+a[1][0]))
				sum+=1;
				//printf("\n%d--%d\n",a[0][1]+a[1][0],sum);
			}
			else if((i==0)&&(j==m)){
				if(is_prime(a[0][m-1]+a[1][m]))
				sum+=1;
				//printf("\n%d--%d\n",a[0][m-1]+a[1][m],sum);
			}
			else if((i==m)&&(j==0)){
				if(is_prime(a[m][1]+a[m-1][0]))
				sum+=1;
				//printf("\n%d--%d\n",a[m][1]+a[m-1][0],sum);
			}
			else if((i==m)&&(j==m)){
				if(is_prime(a[m][m-1]+a[m-1][m]))
				sum+=1;
				//printf("\n%d--%d\n",a[m][m-1]+a[m-1][m],sum);
			}
			else if((i==0)||(j==0)){
				if((i==0)&&(j!=0)&&(j!=m)){
					if(is_prime(a[0][j-1]+a[0][j+1]+a[1][j]))
					sum+=1;
					//printf("\n%d--%d\n",a[0][j-1]+a[0][j+1]+a[1][j],sum);
				}
				else if((j==0)&&(i!=0)&&(i!=m)){
					if(is_prime(a[i][1]+a[i+1][0]+a[i-1][0]))
					sum+=1;
					//printf("\n%d--%d\n",a[i][1]+a[i+1][0]+a[i-1][0],sum);
				}
			}
			else if((i==m)||(j==m)){
				if((i==m)&&(j!=0)&&(j!=m)){
					if(is_prime(a[m][j-1]+a[m][j+1]+a[m-1][j]))
					sum+=1;
					//printf("\n%d--%d\n",a[m][j-1]+a[m][j+1]+a[m-1][j],sum);
				}
				else if((j==m)&&(i!=0)&&(i!=m)){
					if(is_prime(a[i][m-1]+a[i+1][m]+a[i-1][m]))
					sum+=1;
					//printf("\n%d--%d\n",a[i][m-1]+a[i+1][m]+a[i-1][m],sum);
				}
			}
			else{
				if(is_prime(a[i+1][j+1]+a[i-1][j+1]+a[i+1][j-1]+a[i-1][j-1]))
				sum+=1;
				//printf("\n%d--%d\n",a[i+1][j+1]+a[i-1][j+1]+a[i+1][j-1]+a[i-1][j-1],sum);
			}
		}
	}
	printf("%d",sum);
	return 0;
}

int is_prime(int number){
	  int a1[25],i1,j1;
	  for(i1=0;i1<25;i1++)
		  a1[i1]=true;
	  for(i1=2;i1*i1<=number;i1++){
		  if(a1[i1]==true){
			  if(number%i1!=0){
				  for(j1=i1;j1<25;j1+=j1)
				  a1[j1]=false;
			  }
			  else{					//exit if not prime
			  	  j1=-1010;
				  break;
			  }
		  }
		  else
		  continue;
	  }
  	  if(number>=9){
  	  	if(j1==-1010)
  	  	return false;
  	  	else
  	  	return true;
  	  }
  	  else{
  	  	if(number==1||number==2||number==3||number==5||number==7)
			return true;
		else
  	  		return false;
  	  }
}
