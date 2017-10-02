#include <stdio.h>

int main(){
	int t,m,r;
	long n,c1,c2,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%ld %d",&n,&m);
		int a[3][n],s,sum[n+1];
		long s3=0,s11=0,s12=0,s13=0,s21=0,s22=0,s23=0;
		
		for(i=0;i<n;i++)
			sum[i]=a[0][i]=a[1][i]=a[2][i]=0;
		sum[n]=0;
		
		for(i=0;i<m;i++){
			scanf("%d %ld %ld",&r,&c1,&c2);
			for(j=c1-1;j<c2;j++){
				a[r-1][j]=1;
				s=a[0][j]+a[1][j]+a[2][j];
/*
				printf("j=%d s=%d\n",j,s);
//*/
				if(s==3){
					sum[j]=3;}
				else if(s==1){
					if(a[0][j]==1){
			 			sum[j]=11;}
	 				else if(a[1][j]==1){
	 					sum[j]=12;}
 					else if(a[2][j]==1){
 						sum[j]=13;}
				}
				else if(s==2){
					if((a[0][j]+a[1][j])==2){
			 			sum[j]=23;}
	 				else if((a[1][j]+a[2][j])==2){
	 					sum[j]=21;}
 					else if((a[0][j]+a[2][j])==2){
 						sum[j]=22;}
				}
/*
				for(s=0;s<n+1;s++)
					printf("%d ",sum[s]);
				printf("\n");
//*/
			}
/*			
			printf("i=%d\na=\n",i);
			for(j=0;j<n;j++)
				printf("%d ",a[0][j]);
			printf("\n");
			for(j=0;j<n;j++)
				printf("%d ",a[1][j]);
			printf("\n");
			for(j=0;j<n;j++)
				printf("%d ",a[2][j]);
			printf("\nsum=\n");
			for(j=0;j<n+1;j++)
				printf("%d ",sum[j]);
			printf("\n");
//*/
		}		
		int prevs=0,ps11=0,ps12=0,ps13=0,ps21=0,ps22=0,ps23=0,ps3=0;
		for(i=0;i<n+1;i++){
			if((prevs==3 || prevs==0) && sum[i]==3){
				s3++;
				prevs=3;
			}
			else if((prevs==11 || prevs==0) && sum[i]==11){
				s11++;
				prevs=11;
			}
			else if((prevs==12 || prevs==0) && sum[i]==12){
				s12++;
				prevs=12;
			}
			else if((prevs==13 || prevs==0) && sum[i]==13){
				s13++;
				prevs=13;
			}
			else if((prevs==21 || prevs==0) && sum[i]==21){
				s21++;
				prevs=21;
			}
			else if((prevs==22 || prevs==0) && sum[i]==22){
				s22++;
				prevs=22;
			}
			else if((prevs==23 || prevs==0) && sum[i]==23){
				s23++;
				prevs=23;
			}
			else{
				if(sum[i]==3)		s3++;
				else if(sum[i]==11)	s11++;
				else if(sum[i]==12)	s12++;
				else if(sum[i]==13)	s13++;
				else if(sum[i]==21)	s21++;
				else if(sum[i]==22)	s22++;
				else if(sum[i]==23)	s23++;
				if(prevs==3){
					ps3 = ps3>s3?ps3:s3;
					s3=0;
				}
				else if(prevs==11){
					ps11 = ps11>s11?ps11:s11;
					s11=0;
				}
				else if(prevs==12){
					ps12 = ps12>s12?ps12:s12;
					s12=0;
				}
				else if(prevs==13){
					ps13 = ps13>s13?ps13:s13;
					s13=0;
				}
				else if(prevs==21){
					ps21 = ps21>s21?ps21:s21;
					s21=0;
				}
				else if(prevs==22){
					ps22 = ps22>s22?ps22:s22;
					s22=0;
				}
				else if(prevs==23){
					ps23 = ps23>s23?ps23:s23;
					s23=0;
				}
				prevs=0;
			}
		}
		ps3*=3;
		ps23*=2;
		ps22*=2;
		ps21*=2;
		int array[7]={ps3,ps23,ps22,ps21,ps13,ps12,ps11},area;
/*
		printf("Array= ");
		for(i=0;i<7;i++)
			printf("%d ",array[i]);
		printf("\n");
//*/
		area = array[0];
		for (i=1;i<7;i++)
			if (array[i] > area)
				area  = array[i];
		printf("%d\n",area);
	}
	return 0;
}
