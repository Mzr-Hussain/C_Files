#include<stdio.h>

int G[1000][1000],visited[1000],n;    //n is no of vertices and graph is sorted in array G[10][10]

void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
    
    for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
    //if(visited[k]==1) printf("\nvisited %d",k);
}

int main()
{
    int i,j,k;
    printf("Enter number of vertices(n):");
   
    scanf("%d",&n);
 
    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:\n");
   
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
            
	printf("\nEnter Start Point(0 - n-1):");
	
	scanf("%d",&j);

	printf("\nEnter the Point to be verified(0 - n-1):");
	
	scanf("%d",&k);
    
	//visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(j);
    if(visited[k]==1) printf("\nvisited the specified node\n");
	else printf("\ndid not visited the specified node\n");
    return 0;
}
