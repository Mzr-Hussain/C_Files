#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int solution (char** a, int k ,int n) {
   // Write your code here
   int result=0;
   for(int i=0;i<n;i++){
		int row[n];
		for(int j=0; j<n ; j++){
			if(a[i][j]=='P')
				row[j]=1;
			else if(a[i][j]=='T')
				row[j]=0;
		}
		for(int j=0; j<n ; j++){
			if(row[j]==1){
				for(int q=0 ; q <= k ; q++ ){
					if(j+q<n){
						if(row[j+q]==0){
							row[j+q]=-1;
							row[j]=-2;
							result++;
							break;
						}
					}
					else if(j-q >=0){
						if(row[j-q]==0){
							row[j-q]=-1;
							row[j]=-2;
							result++;
							break;
						}
					}
				}
			}
		}
   }
   return result;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        scanf("%d", &N);
        int K;
        scanf("%d", &K);
        int i_A, j_A;
        char **A = (char **)malloc(N*sizeof(char *));
        for(i_A=0; i_A<N; i_A++)
        {
        	A[i_A] = (char *)malloc(N*sizeof(char));
        }
        for(i_A=0; i_A<N; i_A++)
        {
        	for(j_A=0; j_A<N; j_A++)
        	{
        		scanf(" %c", &A[i_A][j_A]);
        	}
        }
        

        int out_ = solution(A, K, N);
        printf("%d", out_);
        printf("\n");
    }
}