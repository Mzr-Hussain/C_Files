#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int print[128];
char org[26],map[26];

int map_to_original(char in){
	int i,ind=0;
	char out=in,rep[26];
	for(i=0;i<26;i++)
		rep[i]='!';
	while(out>96 && out<123){
		for(i=0;i<26;i++){
			if(rep[i]==in)
				return 0;
		}
		for(i=0;i<26;i++){
			if(org[i]==in){
				rep[ind]=in;
				ind++;
				break;
			}
		}
		if(i==26) return -1;
		out = in = map[i];
	}
	return out-'0';
}

int main(){
	int tst_case,t,rules_no,i;
	char input[128];
	scanf("%d",&tst_case);
	for(t=1;t<=tst_case;t++){
		printf("#%d\n",t);
		scanf("%d",&rules_no);
		for(i=0;i<rules_no;i++){
//			scanf("%c %c",&org[i],&map[i]);
			getchar();
			org[i]=getchar();
			getchar();
			map[i]=getchar();
//			printf("{%c-%c}\n",org[i],map[i]);
		}
		int tst_string,len;
		scanf("%d",&tst_string);
		while(tst_string--){
			scanf("%s",&input);
			len=strlen(input);
			int flag=1;
			for(i=0;i<len;i++){
				print[i]=map_to_original(input[i]);
				if(print[i]==-1){
					printf("-1\n");
					flag =0;
					break;
				}
			}
			if(flag){
				for(i=0;i<len;i++)
					printf("%d",print[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
