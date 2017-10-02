#include<stdio.h>
#include<math.h>
float inreal[4],inimag[4],outreal[4],outimag[4];
int main(){
	int i;
	printf("Enter the input for 4 point fft:\n");
	for(i=0;i<4;i++)
		scanf("%f %f",&inreal[i],&inimag[i]);
	
	outreal[0]=inreal[0]+inreal[2]+inreal[1]+inreal[3];
	outreal[1]=inreal[0]-inreal[2]+inreal[1]-inreal[3];
	outreal[2]=inreal[0]+inreal[2]-inreal[1]-inreal[3];
	outreal[3]=inreal[0]-inreal[2]-inimag[1]+inimag[3];
	
	outimag[0]=inimag[0]+inimag[2]+inimag[1]+inimag[3];
	outimag[1]=inimag[0]-inimag[2]+inimag[1]-inimag[3];
	outimag[2]=inimag[0]+inimag[2]-inimag[1]-inimag[3];
	outimag[3]=inimag[0]-inimag[2]+inreal[1]-inreal[3];
		
	printf("The fft of the given 4 point sequence is:\n");
	printf("Real\tImaginary\n");
	for(i=0;i<4;i++)
		printf("%0.3f\t%0.3f\n",outreal[i],outimag[i]);
	return 0;
}
