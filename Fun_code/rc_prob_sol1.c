#include <stdio.h>
#include <stdlib.h>

int len;

char* file_read(){
	FILE *fptr;
	char filename[100],c[100000];
	printf("Enter the filename to open \n");
	scanf("%s", filename);
	//Open file
	fptr = fopen(filename, "r");
	if (fptr == NULL){
		printf("Cannot open file \n");
		exit(0);
	}
	// Read contents from file
	int i=0;
	c[i] = fgetc(fptr);
	while (c[i] != EOF){
		i++;
		c[i] = fgetc(fptr);
	}
	len=i;
	fclose(fptr);
	return c;
}

int next_space(char *fi){
	static int i=-1;
	i++;
	while(fi[i] !=' ')
		i++;
	return i;
}

int next(int now, int *rema, int n){
	int i=now;
	while(rema[i%(n+1)]==0)
		i++;
	return i%(n+1);
}

int main()
{
    int n,k,start,flag;
/*
//	this is to read from file
	char *fi=file_read();
	n=atoi(fi);
	k=atoi(fi+next_space(fi));
	start=atoi(fi+next_space(fi));
//  char *num = "1024";
//	int val = atoi(num);  
*/
	scanf("%d %d %d",&n,&k,&start);
	int rem=n,rema[n+1],i=0;
    for(;i<n+1;i++)
        rema[i]=1;
    rema[0]=0;
    while(start%k<rem){
        for(i=start+1,flag=0;flag<(start%k);i++){
            if(rema[i%(n+1)]){
                rema[i%(n+1)]=0;
                flag++;
            }
        }
        rem-=start%k;
        start=next((i%(n+1)), rema, n);
    }
    printf("%d",start);
    return 0;
}
