#include<stdio.h>
#define max 100						//maxium prime number needed to check is (let) k then, k*k<=max
#define true 0
#define false 1 
int main(){
	while(1){
	  int a[max],i,j,number;
	  scanf("%d",&number);
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
				  	  j=1010;
					  break;
				  }
			  }
			  else
			  continue;
		  }
		  if(j==1010)
		  printf("not prime\n");
  	  	  else
  	  	  printf("prime\n");
	  }
	  else printf("number less than 2\n");
	}
	return 0;
}
