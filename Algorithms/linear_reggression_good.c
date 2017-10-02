#include <stdio.h>
#include <math.h>
int main(){
    float xx[5],yy[5],nr=0,dr=0;
    float x[5]={60,61,62,63,65},y[5]={3.1,3.6,3.8,4.0,4.1};
    double sum_y=0,sum_xy=0,sum_x=0,sum_xx=0,sum_x2=0,slope=0,intercept=0,reg;
    int i,n=5;
    for(i=0;i<n;i++){
	    xx[i]=x[i]*x[i];
	    yy[i]=y[i]*y[i];
    }
    for(i=0;i<n;i++){
	    sum_x+=x[i];
	    sum_y+=y[i];
	    sum_xx+= xx[i];
	    sum_xy+= x[i]*y[i];
    }
    nr=(n*sum_xy)-(sum_x*sum_y);
    sum_x2=sum_x*sum_x;
    dr=(n*sum_xx)-sum_x2;
    slope=nr/dr;
    double fac = pow(10, 2);
    slope=round(slope*fac)/fac;       
    intercept=(sum_y- slope*sum_x)/n;
    reg= intercept + (slope*64);
    printf("Slope: %.2f\nIntercept: %.3f\nRegression: %.3f",slope,intercept,reg);
    return 0;
}