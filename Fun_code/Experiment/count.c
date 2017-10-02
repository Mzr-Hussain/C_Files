#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *fp;
	fp=fopen("DATA.txt","r");
	if(fp==NULL){										//exit program if file doesn’t open
		printf("File could not open!!");
		exit(0);
	}
	int sum0=0,sum1=0;
	char c = fgetc(fp);
    while (c != EOF)
    {
        if(c=='0')
			sum0++;
		else if(c=='1')
			sum1++;
        c = fgetc(fp);
    }
	fclose(fp);
	printf("0-%d\n1-%d\ntotal-%d",sum0,sum1,sum0+sum1);
}