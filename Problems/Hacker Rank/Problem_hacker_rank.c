#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int R; 
        int C; 
        scanf("%d %d",&R,&C);
        char **G = (char **)malloc(R * sizeof(char *));
        for(int G_i = 0; G_i < R; G_i++){
            G[G_i] = (char *)malloc(C * sizeof(char));
            scanf("%s",G[G_i]);
        }
        int r; 
        int c; 
        scanf("%d %d",&r,&c);
        char **P = (char **)malloc(r * sizeof(char *));
        for(int P_i = 0; P_i < r; P_i++){
            P[P_i] = (char *)malloc(c * sizeof(char));
            scanf("%s",P[P_i]);
        }
        int flag = 0;
		char buffer[100]={'\0'},buffer2[100]={'\0'};
        for(int i = 0; i<=R-r ; i++ ){
            for(int j = 0 ; j<=C-c ; j++ ){
                if(G[i][j] == P[0][0]){
                    flag = 1;
                    for(int ii=i ; ii<r+i ;ii++){
						strcat(buffer,"\n");
                        strcat(buffer2,"\n");
						for(int jj=j+1 ; jj<c+j ; jj++){
							strcat(buffer,G[ii][jj]);
							strcat(buffer," ");
                            strcat(buffer2,P[ii-i][jj-j]);
							strcat(buffer2," ");
							if(G[ii][jj] != P[ii-i][jj-j]){
                                flag=0;
                                goto nxt_element;
                            }
                        }
                    }
                }
                nxt_element:
				printf("G:-");
                printf("%s\n",buffer);
				printf("P:-");
                printf("%s\n",buffer2);
				if(flag==1){
                    flag=0;
                    goto print;
                }
            }
        }
        print:
        if(flag==1)
        printf("YES\n");
        else
        printf("NO\n");
      free(G);
      free(P);
    }
    return 0;
}
