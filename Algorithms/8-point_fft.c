#include<stdio.h>

float inreal[8],inimag[8],midreal[8],midimag[8],outreal[8],outimag[8];
int main(){
	int i;
	printf("Enter the input for 8 point fft:\n");
	for(i=0;i<8;i++)
		scanf("%f %f",&inreal[i],&inimag[i]);

/*	DESIMATION IN FREQUENCY FAST FORIER TRANSFORM:
	
	X(0)-->--+-------+-----midreal[0]+midimag[0]-----+-------+-->--+-----------+-----> x(0)
             |       |                               |       |     |2-point dft|
	X(1)-->--|       |-----midreal[1]+midimag[1]-----|4-point|-->--+-----------+-----> x(4)
             |       |                               |       |
	X(2)-->--|       |-----midreal[2]+midimag[2]-----|  dft  |-->--+-----------+-----> x(2)
	         |       |                               |       |     |2-point dft|
	X(3)-->--|8-point|-----midreal[3]+midimag[3]-----+-------+-->--+-----------+-----> x(6)
	         |       |
	X(4)-->--|  dft  |-----midreal[4]+midimag[4]-----+-------+-->--+-----------+-----> x(1)
	         |       |                               |       |     |2-point dft|
	X(5)-->--|       |-----midreal[5]+midimag[5]-----|4-point|-->--+-----------+-----> x(5)
	         |       |                               |       |
	X(6)-->--|       |-----midreal[6]+midimag[6]-----|  dft  |-->--+-----------+-----> x(3)
	         |       |                               |       |     |2-point dft|
	X(7)-->--+-------+-----midreal[7]+midimag[7]-----+-------+-->--+-----------+-----> x(7)
	
*/

//  1st step decimation in frequency implementation of 4-point butterfly
	
//  first four real:
	midreal[0]=inreal[0]+inreal[4];
	midreal[1]=inreal[1]+inreal[5];
	midreal[2]=inreal[2]+inreal[6];
	midreal[3]=inreal[3]+inreal[7];	
//  last four real:
	midreal[4]=inreal[0]-inreal[4];
	midreal[5]=0.707*(inreal[1]-inreal[5]+inimag[1]-inimag[5]);
	midreal[6]=inimag[2]-inimag[6];
	midreal[7]=0.707*(-inreal[3]+inreal[7]+inimag[3]-inimag[7]);
//  first four imaginary:
	midimag[0]=inimag[0]+inimag[4];
	midimag[1]=inimag[1]+inimag[5];
	midimag[2]=inimag[2]+inimag[6];
	midimag[3]=inimag[3]+inimag[7];
//  last four imaginary:
	midimag[4]=inimag[0]-inimag[4];
	midimag[5]=0.707*(inimag[1]-inimag[5]-inreal[1]+inreal[5]);
	midimag[6]=-inreal[2]+inreal[6];
	midimag[7]=0.707*(-inimag[3]+inimag[7]-inreal[3]+inreal[7]);
	
//  2nd and 3rd step decmaion in frequency: two 4-point fft and four 2-point fft 
	
	outreal[0]=midreal[0]+midreal[1]+midreal[2]+midreal[3];
	outreal[4]=midreal[0]-midreal[1]+midreal[2]-midreal[3];
	outreal[2]=midreal[0]+midimag[1]-midreal[2]-midimag[3];
	outreal[6]=midreal[0]-midimag[1]-midreal[2]+midimag[3];
	
	outreal[1]=midreal[4]+midreal[5]+midreal[6]+midreal[7];
	outreal[5]=midreal[4]-midreal[5]+midreal[6]-midreal[7];
	outreal[3]=midreal[4]+midimag[5]-midreal[6]-midimag[7];
	outreal[7]=midreal[4]-midimag[5]-midreal[6]+midimag[7];
	
	outimag[0]=midimag[0]+midimag[1]+midimag[2]+midimag[3];
	outimag[4]=midimag[0]-midimag[1]+midimag[2]-midimag[3];
	outimag[2]=midimag[0]-midreal[1]-midimag[2]+midreal[3];
	outimag[6]=midimag[0]+midreal[1]-midimag[2]-midreal[3];
	
	outimag[1]=midimag[4]+midimag[5]+midimag[6]+midimag[7];
	outimag[5]=midimag[4]-midimag[5]+midimag[6]-midimag[7];
	outimag[3]=midimag[4]-midreal[5]-midimag[6]+midreal[7];
	outimag[7]=midimag[4]+midreal[5]-midimag[6]-midreal[7];
	
//values are stored in outreal[] and outimag[]
//printing the output
	
	printf("The fft of the given 8 point sequence is:\n");
	printf("Real\tImaginary\n");
	for(i=0;i<8;i++)
		printf("%0.3f\t%0.3f\n",outreal[i],outimag[i]);

	return 0;
}