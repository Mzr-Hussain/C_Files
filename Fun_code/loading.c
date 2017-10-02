#include <stdio.h>

int main(){
 	long i;
 	printf(" ");
 	for(;;){
	 	printf("\b|");
	 	for(i=0;i<30000000;i++);
	 	printf("\b/");
	 	for(i=0;i<30000000;i++);
	 	printf("\b-");
	 	for(i=0;i<30000000;i++);
	 	printf("\b\\");
	 	for(i=0;i<30000000;i++);
	 }
 	return 0;
}
