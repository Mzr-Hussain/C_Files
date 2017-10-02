#include <stdio.h>
#include <string.h>

int main(){
	int t,n1,n2,i,j,a;
	scanf("%d",&t);
	while(t--){
		char s1[10000],s2[10000];
		scanf("%s %s",&s1,&s2);
		n1 = strlen(s1);
		n2 = strlen(s2);
		a=0;
		for(i=0;i<n1;i++){
			for(j=0;j<n2;j++)
				if(s1[i]==s2[j]){
					a++;
					s1[i]='0';
					s2[j]='1';
				}
		}
		printf("%ld\n",n1+n2-2*a);
	}
	return 0;
}
