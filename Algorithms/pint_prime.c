#include<stdio.h>
#define true 1
#define false 0
int main(){
	long long unsigned number=0,sum=0,p,q;
	scanf("%llu",&p);
	for(q=0;q*q<=p;q++);
	while(number<p){
	  int a1[q],i1,j1;
	  for(i1=0;i1<q;i1++)
		  a1[i1]=true;
	  for(i1=2;i1*i1<=number;i1++){
		  if(a1[i1]==true){
			  if(number%i1!=0){
				  for(j1=i1;j1<q;j1+=j1)
				  a1[j1]=false;
			  }
			  else{					//exit if not prime
			  	  j1=-1;
				  break;
			  }
		  }
		  else
		  continue;
	  }
  	  if(number>=9){
  	  	if(j1!=-1)
  	  	printf("%llu ",number);
  	  }
  	  else{
  	  	if(number==2||number==3||number==5||number==7)
	  	  	printf("%llu ",number);
  	  }
  	  number+=1;
	}
	return 0;
}
