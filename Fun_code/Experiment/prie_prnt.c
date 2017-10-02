#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int isprime(int);

int main()
{
	FILE *fp;
	fp=fopen("DATA.txt","w");
	if(fp==NULL){										//exit program if file doesn’t open
		printf("File could not open!!");
		exit(0);
	}
    int i,n1=0,flag;
    fprintf(fp,"{");
    for(i=6390;n1<=5;i++){
		flag=isprime(i);
        if(flag == 1 ){
			n1++;
			fprintf(fp," %d,",i);
		}
    }
    fprintf(fp,"}\n");
	fprintf(fp,"\n%d\n\n",i);
	/*
    fprintf(fp,"{");
    for(int i=1;i<=1000;i++){
        int n=isprime(i);
        fprintf(fp," %d,",n);
    }
	while(n1--){
        fprintf(fp," 1,",n1);
	}
	fprintf(fp,"}");
	*/
	fclose(fp);
    return 0;
}

int isprime(int n){
    if(n>1){
    	int i;
        for(i=2;i<n;i++){
            if(n%i==0){
                return 0;
            }
        }
    }
    else if(n==1)
        return 0;
    return 1;
}