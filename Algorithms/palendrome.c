#include <stdio.h>
#include <string.h>

int ispal(const char *s){
 	const char *p = s+strlen(s)-1;
	while (s < p)
		if (*p-- != *s++)
			return 0;
	return 1;
}

int main()
{
    char c[100];
/*
    fgets (c, 100, stdin);
    len=strlen(c);
    if(len&1)   n=(len+1)/2;
    else        n=len/2;
    for(i=0;i<strlen(c);i++){
        if(c[i]!=r[i]){
            flag=1;
            break;
        }
    }
    if(flag==1) printf("NO");
    else        printf("YES");
*/
    scanf("%s",&c);
/*
    char temp;
	int i=0;
	int j=strlen(c)-1;
    strcpy(r,c);
	while(i<j){
		temp = c[i];
		c[i] = c[j];
		c[j] = temp;
		i++;
		j--;
	}
*/
	if(ispal(c))		printf("YES");
    else				printf("NO");
    return 0;
}
