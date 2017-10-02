#include<stdio.h>
#include<stdlib.h>
#define False 0
#define True 1

int global_n=0,global_visit=False;
int visited[100000];
//char *ROAD = (char *) malloc(10000000000*sizeof(char));

void DFS(int i,int road[global_n][global_n]){
    int j;
    visited[i]=True;
    for(j=0;j<global_n;j++)
       if(!visited[j]&&road[i][j]==1)
            DFS(j,road);
}

int main(){
	int n,q,rr,u,v,i,j,k;
	scanf("%d %d",&n,&q);
	global_n=n;
	int rail[n][n],road[n][n];
/*	
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			rail[i][j]=road[i][j]=rail[j][i]=road[j][i]=False;	//  False indicates default value
	}
*/	
	while(q!=0){
		scanf("%d %d %d",&rr,&u,&v);
		if(u!=v){
			if(rr==1)													//build rail connection
				rail[u-1][v-1]=rail[v-1][u-1]=True;
			else if(rr==2)												//build road connection
				road[u-1][v-1]=road[v-1][u-1]=True;
		}
	
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(rail[i][j]==1){
					for(k=0;k<n;k++)
        				visited[k]=0;
					DFS(i,road);
					if(visited[j]==False) {global_visit=False; goto exit;}
				}
			}
		}

exit:	(global_visit==True)? printf("YES\n"):printf("NO\n");
		global_visit=True;
		q--;
	}
}
