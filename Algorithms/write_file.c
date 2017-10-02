#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
	FILE *fp;
	char ch,file[10];
	printf("Enter file name:");
	scanf("%s",file);
	
	fp=fopen(file,"w");									//file opening
	if(fp==NULL){										//exit program if file doesn’t open
		printf("File could not open!!");
		exit(0);
	}
	
	printf("Enter data(* to exit):\n");
	while(1){
		ch=getchar();
		if(ch=='*')										//exit when * is pressed
		exit(0);
		putc(ch,fp);
	}
	fclose(fp);											//file closing
}
