#include<stdio.h>
int n,m,Xi,Yi,Xf,Yf;

void path_assign(int *mat_num){
	// *((arr+i*n) + j)  = a[i][j]
	int i,j,iteration=1,found=0;

	out:if(found!=1){
			for(i=0;i<n+2;i++){
				for(j=0;j<m+2;j++){
					if(*((mat_num+i*(m+2))+j)==iteration-1){
						if(((*((mat_num+(i-1)*(m+2))+j))==-1 || (*((mat_num+(i-1)*(m+2))+j))==-2 || (*((mat_num+(i-1)*(m+2))+j))==-3) && (i-1)>=0 && (*((mat_num+(i-1)*(m+2))+j)==-1)){
							(*((mat_num+(i-1)*(m+2))+j))==iteration;
							if((*((mat_num+(i-1)*(m+2))+j)==-3)){
								found = 1;
								goto out;
							}
						}
						if(((*((mat_num+(i+1)*(m+2))+j))==-1 || (*((mat_num+(i+1)*(m+2))+j))==-2 || (*((mat_num+(i+1)*(m+2))+j))==-3) && (i+1)<n+2 && (*((mat_num+(i+1)*(m+2))+j)==-1)){
						 (*((mat_num+(i+1)*(m+2))+j))==iteration;
							if((*((mat_num+(i+1)*(m+2))+j)==-3)){
								found = 1;
								goto out;
							}
						}
						if(((*((mat_num+(i)*(m+2))+(j-1)))==-1 ||(*((mat_num+(i)*(m+2))+(j-1)))==-2||(*((mat_num+(i)*(m+2))+(j-1))==-3)) && (j-1)>=0 && (*((mat_num+(i)*(m+2))+(j-1))==-1)){
							(*((mat_num+(i)*(m+2))+(j-1)))==iteration;
							if((*((mat_num+(i)*(m+2))+(j-1))==-3)){
								found = 1;
								goto out;
							}
						}
						if(((*((mat_num+(i)*(m+2))+(j+1)))==-1 ||(*((mat_num+(i)*(m+2))+(j+1)))==-2||(*((mat_num+(i)*(m+2))+(j+1))==-3)) && (j+1)<m+2 && (*((mat_num+(i)*(m+2))+(j+1))==-1)){
							(*((mat_num+(i)*(m+2))+(j+1)))==iteration;
							if((*((mat_num+(i)*(m+2))+(j+1))==-3)){
								found = 1;
								goto out;
							}
						}
					}//End if
				}//End for innner
			}//End for outer
			iteration++;
		}//End if found
}

int main(){
	int i,j;
	scanf("%d %d ",&n,&m);
	char mat[n][m];
	int mat_num[n+2][m+2];
	for(i=0;i<n+2;i++){
		for(j=0;j<m+2;j++)
			mat_num[i][j]=-4;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mat_num[i+1][j+1]=-1;
			scanf("%c",&mat[i][j]);
			if(mat[i][j]=='V'){
				Xi=i;
				Yi=j;
				mat_num[i+1][j+1]=0;
			}
			if(mat[i][j]=='H'){
				Xf=i;
				Yf=j;
				mat_num[i+1][j+1]=-2;
			}
			if(mat[i][j]=='*')
				mat_num[i+1][j+1]=-3;
		}
		getchar();
	}
	path_assign(&mat_num[0][0]);
	
	printf("\n");
	for(i=0;i<n+2;i++){
		for(j=0;j<m+2;j++)
//			printf("%d\t",mat_num[i][j]);
			printf("%d\t", *((&mat_num[0][0]+i*(m+2))+j));			
		printf("\n");
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
//			printf("%c\t",mat[i][j]);
			printf("%c\t", *((&mat[0][0]+i*m)+j));
		printf("\n");
	}
	
	return 0;
}

/*
*******************************************************************************
						CODE FORM MAZE SOLVER VIDEO
*******************************************************************************

int i,j,found=0,moreoves=1;
	while(found != 1&& moremoves == 1){
		moremoves = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				xP=j;
				yP=i;
				if(flood[i][j]==(itt - 1)){
					if(((char)maze[yP-1][xP] == '.' || (char)maze[yP-1][xP] == 'V' || (char)maze[yP-1][xP] == 'H') && (yP - 1) >= 0 && flood[yP-1][xP] == -1){
						flood[yP-1][xP] = itt;
						moremoves = 1;
						if((char)maze[yP-1][xP] == 'H'){
							flood[yP-1][xP] = itt;
							found = 1;
						}
					}
					if(((char)maze[yP+1][xP] == '.' || (char)maze[yP+1][xP] == 'V' || (char)maze[yP+1][xP] == 'H') && (yP + 1) < y && flood[yP+1][xP] == -1){
						flood[yP+1][xP] = itt;
						moremoves = 1;
                        if((char)maze[yP+1][xP] == 'H'){
							flood[yP+1][xP] = itt;
							found = 1;
						}
					}
                    if(((char)maze[yP][xP-1] == '.' || (char)maze[yP][xP-1] == 'V' || (char)maze[yP][xP-1] == 'H') && (xP - 1) >= 0 && flood[yP][xP - 1] == -1){
						flood[yP][xP - 1] = itt;
						moremoves = 1;
                        if((char)maze[yP][xP-1] == 'H'){
							flood[yP][xP-1] = itt;
							found = 1;
						}
					}if(((char)maze[yP][xP+1] == '.' || (char)maze[yP][xP+1] == 'V' || (char)maze[yP][xP+1] == 'H') && (xP + 1) < x && flood[yP][xP + 1] == -1){
						flood[yP][xP + 1] = itt;
						moremoves = 1;
                        if((char)maze[yP][xP+1] == 'H'){
							flood[yP][xP+1] = itt;
							found = 1;
						}
					}
				}// End if
			}// End Inner For Loop
		}//End Outer For Loop
		itt++;
		moves++;
	}//End Main While Loop
*/


/*

*************************
     IMPORTANT NOTES
*************************

matrix[0][0] = *(*(matrix))
matrix[i][j] = *((*(matrix)) + (i * COLS + j))
matrix[i][j] = *(*(matrix + i) + j)
matrix[i][j] = *(matrix[i] + j)
matrix[i][j] = (*(matrix + i))[j]
&matrix[i][j] = ((*(matrix)) + (i * COLS + j))

*/