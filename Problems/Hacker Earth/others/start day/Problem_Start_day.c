#include <stdio.h>

int main()
{
    short t,i,j;
    long k,a[7],sum=0;
    scanf("%d",&t);
    while(t--){
        scanf("%ld",&k);
		for(i=0;i<7;i++){
			scanf("%ld",&a[i]);
			sum+=a[i];
		}
        if(k<=sum){
        	for(i=0;k>0;i++)
	        	k-=a[i];
        	i--;
        	j=1;
        }
        else{
        	k%=sum;
        	if(k!=0){
        		for(i=0;k>0;i++)
	        		k-=a[i];
        		i--;
	        }
	        else{
        		for(i=0;i<6;i++)
        			if(a[i]==1)
        				break;
        	}
        	j=2;
        }
//        printf("(j=%d) (k=%d) (i=%d)",j,k,i);
        if(i==0)   		printf("MONDAY\n");
        else if(i==1)   printf("TUESDAY\n");
        else if(i==2)   printf("WEDNESDAY\n");
        else if(i==3)   printf("THURSDAY\n");
        else if(i==4)   printf("FRIDAY\n");
        else if(i==5)   printf("SATURDAY\n");
    	else if(i==6)   printf("SUNDAY\n");
     }
    return 0;
}
