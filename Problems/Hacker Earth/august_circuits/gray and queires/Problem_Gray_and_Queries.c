#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *s, size_of_S, number=0;

void check_if_present(int sub_string[],int len){
	int i,j,count=0,count_less=0;
	for(i=0;i<size_of_S;i++){
		printf("%d-------------------------------i--------------------------------\n",i);
		for(j=0;j<len;j++){
			printf("%d-------------------------------j--------------------------------\n",j);
			if(s[i]==sub_string[j]){
				count++;
				break;
			}
		}
		if((count_less+1)!=count)	break;
		else						count_less++;
	}
	if(count==size_of_S)			number++;
}

void call_substring(int str[],int str_length){
	int k,i,len,num;
	printf("*************");
	for(len=size_of_S;len<=str_length;len++){
		printf("%d--len--",len);
		int *sub_string = (int*)malloc(len*sizeof(int));
//		int sub_string[len];
		for(i=0;i<=str_length-len;i++){
			printf("%d--i--\n",i);
			for(k=i;k<=(i+len-1);k++)
				sub_string[k-i]= str[k];
			num=number;
			printf("%d--k_final--\n",k);
			check_if_present(sub_string,len);
			
			printf("\n");
/*
			if(num+1==number){
				for(k=i;k<=j;k++)
					printf("%d",str[k]);
				printf(" ");
			}
*/
		}
		free(sub_string);
	}
	printf("\n");
}

int main(){
	int *x,n,i;
	
	//char *num = "1024";
	//int val = atoi(num);
	//here val=1024	
	//char *X;
	//X=(char*) malloc(100000* sizeof(char));
	
	char X[100000];
	scanf("%s",&X);
	for(n=0;X[n]!='\0';n++);
	x=(int*) malloc((n)* sizeof(int));
	for(i=0;i<n;i++)
		x[i]=X[i]-'0';
	scanf("%d",&size_of_S);
	s=(int*) malloc((size_of_S-1)* sizeof(int));
	for(i=0;i<size_of_S;i++)
		scanf("%d",&s[i]);
	call_substring(x,n);
	printf("%d",number);
	free(x);
	free(s);
	return 0;
}
