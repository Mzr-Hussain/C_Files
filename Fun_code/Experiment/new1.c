#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 10000000

void fill_square_area( unsigned long long , unsigned long long , FILE * );

int main() {
	FILE *fp;
	fp=fopen("DATA.txt","w");
	unsigned long long a=1;
	unsigned long long b=1;
	while( 0<a && a<MAX_NUMBER){
		fill_square_area(a,b,fp);
		a+=b;
		b+=a;
	}
	fclose(fp);
	return 0;
}

void fill_square_area( unsigned long long a , unsigned long long b ,FILE *fp){
	static char inc=33;
	a/=500;
	b/=500;
	unsigned long long i,j;
	for(i=1;i<=a;i++){
		for(j=1;j<=a;j++)
			fprintf(fp,"%c",inc);
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	inc++;
	for(i=1;i<=b;i++){
		for(j=1;j<=b;j++)
			fprintf(fp,"%c",inc);
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	inc++;
}