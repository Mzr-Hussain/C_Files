#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define true 1
#define false 0

typedef struct node
{
   int data;
   struct node* left;
   struct node* right;
   int index;
}Tree;

int sum;
Tree *root_node;

int getLevelUtil(Tree *node, int index_data, int level){
    if (node == NULL)
        return 0; 
    if (node->index == index_data)
        return level;
    int downlevel = getLevelUtil(node->left, index_data, level+1);
    if (downlevel != 0)
        return downlevel;
    downlevel = getLevelUtil(node->right, index_data, level+1);
    return downlevel;
}

int getLevel(Tree *node, int index_data)
{
	static void *ptr=NULL;
	if(ptr == NULL)
		ptr=node;
	return getLevelUtil(ptr,index_data,1);
}

int printAncestors(Tree *root, Tree *target, int k){
	/* Previous code
	if (root == NULL)
		return false;
	if ( root->data == target->data && root->index==index){
		return true;
	}
	if ( (printAncestors(root->left, target->data, index) || printAncestors(root->right, target->data, index)) ){
		printf("%d ",root->data);
		return true;
	}
	return false;
	//*/
	// present code
	int target_level=getLevel( root, target->index);
	int root_level=getLevel( root, root->index);
	if( root==NULL || root==target || root_level>target_level )
		return false;
	if( target_level-root_level>=k ){
	if( root->data==target->data )
		sum++;
	printAncestors(root->left, target, k);
	printAncestors(root->right, target, k);
	}
	return true;
}

Tree* newnode(int data, int index)
{
  Tree* node = (Tree*)malloc(sizeof(Tree));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->index = index;
 
  return(node);
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int x,y,colour;
    Tree *a[n];
	for(int i=0;i<n;i++){
        scanf("%d",&colour);
		a[i]=newnode( colour, i+1);
	}
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&x,&y);
		int min = x<y?x:y;
		int max = x>y?x:y;
		x=min-1;
		y=max-1;
		if( (a[x]->left)== NULL ){
			a[x]->left  = a[y];
		}
		else if( (a[x]->right)== NULL ){
			a[x]->right = a[y];
		}
	}
//*
	for(int i=0;i<n;i++){
		printAncestors(a[0], a[i], k);
		if(sum!=0)
			printf("%d ",sum);
		else
			printf("-1 ");
		sum=0;
	}
	
/*	
    Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
//*/
	return 0;
}