#include<stdio.h>
#define true 1
#define false 0 
int main(){
	  int a1[25],i1,j1,number;
	  while(1){
  	  scanf("%d",&number);
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
  	  	printf("not prime\n");
  	  	else
  	  	printf("prime\n");
  	  }
  	  else{
  	  	if(number==1||number==2||number==3||number==5||number==7)
			printf("prime\n");
		else
  	  		printf("not prime\n");
  	  }
  	}
}
