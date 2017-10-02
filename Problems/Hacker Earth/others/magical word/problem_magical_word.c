#include<stdio.h>
 
int main(){
	int t,n,i,j;
	int c[12]={67,71,73,79,83,89,97,101,103,107,109,113};
	scanf("%d",&t);
	while(t!=0){
		scanf("%d",&n);
		char a[n],b[n];
		scanf("%s",a);
		for(i=0;i<n;i++){
			if(((int)a[i]==67)||((int)a[i]==71)||((int)a[i]==73)||((int)a[i]==79)||((int)a[i]==83)||((int)a[i]==89)||((int)a[i]==97)||((int)a[i]==101)||((int)a[i]==103)||((int)a[i]==107)||((int)a[i]==109)||((int)a[i]==113))
				b[i]=a[i];
			else{
				if((int)a[i]<=67)
				b[i]='C';
				else if((int)a[i]>=113)
				b[i]='q';
				else{
					for(j=1;j<12;j++){
						if(((int)a[i])<=c[j]){
							if((int)a[i]<=((c[j]+c[j-1])/2))
							b[i]=(char)c[j-1];
							else
							b[i]=(char)c[j];
							break;
						}
					}
				}
			}
		}
		for(i=0;i<n;i++)
		printf("%c",b[i]);
		printf("\n");
		t--;
	}
	return 0;
}
