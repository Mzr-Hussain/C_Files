#include<stdio.h>

int main(){
	int n,I;
	float sumx=0, sumxsq=0, sumy=0, sumxy=0, x=0, y=0, a0=0, a1=0, recur ,i;
	printf("enter the n value");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%f %f", &x, &y);
		sumx += x;
		sumxsq += (sumx * sumx);
		sumy += y;
		sumxy += x * y;
	}
	recur = n * sumxsq - (sumx * sumx);					//pow(sumx, 2)
	if(recur!=0){		
		a0 = (sumy * sumxsq - sumx * sumxy) / recur;
		a1 = (n * sumxy - sumx * sumy) / recur;
	}
	else{		
		a0 = (sumy * sumxsq - sumx * sumxy);
		a1 = (n * sumxy - sumx * sumy);
	}
	printf("y = %fx + %f", a1, a0);
}
