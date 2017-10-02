#include <stdio.h>
#define r   move_right();
#define ra  move_right1();
#define l   move_left();
#define la  move_left1();
#define t   move_top();
#define ta  move_top1();
#define d   move_down();
#define da  move_down1();
#define f   move_front();
#define fa  move_front1();
#define b   move_back();
#define ba  move_back1();

//r2a=r2,l2a=l2,... and so on

#define r2  move_right();	move_right();
#define r2a move_right1();	move_right1();
#define l2  move_left();	move_left();
#define l2a move_left1();	move_left1();
#define t2  move_top();		move_top();
#define t2a move_top1();	move_top1();
#define d2  move_down();	move_down();
#define d2a move_down1();	move_down1();
#define f2  move_front();	move_front();
#define f2a move_front1();	move_front1();
#define b2  move_back();	move_back();
#define b2a move_back1();	move_back1();

#define white	1
#define red		2
#define yellow	3
#define green	4
#define blue	5
#define orange	6

#define W	1
#define R	2
#define Y	3
#define G	4
#define B	5
#define O	6

/*
default_cube[6][3][3]=	{{		{1,1,1},{1,1,1},{1,1,1}		},		//top
						{		{2,2,2},{2,2,2},{2,2,2}		},		//front
						{		{3,3,3},{3,3,3},{3,3,3}		},		//bottom
						{		{4,4,4},{4,4,4},{4,4,4}		},		//left
						{		{5,5,5},{5,5,5},{5,5,5}		},		//right
						{		{6,6,6},{6,6,6},{6,6,6}		}}		//back
*/
int i=0,j=0,k=0;

int  cube[6][3][3]=	{{		{W,W,W},{W,W,W},{W,W,W}		},		//top
					{		{R,R,R},{R,R,R},{R,R,R}		},		//front
					{		{Y,Y,Y},{Y,Y,Y},{Y,Y,Y}		},		//bottom
					{		{G,G,G},{G,G,G},{G,G,G}		},		//left
					{		{B,B,B},{B,B,B},{B,B,B}		},		//right
					{		{O,O,O},{O,O,O},{O,O,O}		}};		//back
					
int aux_cube[6][3][3];

void Call_Aux_Map_Cube(){
	for(i=0;i<6;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++)
				aux_cube[i][j][k]=cube[i][j][k];
		}
	}
}

void move_right(){
	Call_Aux_Map_Cube();

//right clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[4][i][j]=aux_cube[4][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][j][2]=aux_cube[1][j][2];

//front rotate	

	for(j=0;j<3;j++)
		cube[1][j][2]=aux_cube[2][j][2];

//bottom rotate	

	for(j=0;j<3;j++)
		cube[2][j][2]=aux_cube[5][2-j][0];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][j][0]=aux_cube[0][2-j][2];
}

void move_right1(){
	Call_Aux_Map_Cube();

//right anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[4][i][j]=aux_cube[4][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][j][2]=aux_cube[5][2-j][0];

//front rotate	

	for(j=0;j<3;j++)
		cube[1][j][2]=aux_cube[0][j][2];

//bottom rotate	

	for(j=0;j<3;j++)
		cube[2][j][2]=aux_cube[1][j][2];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][j][0]=aux_cube[2][2-j][2];
}

void move_left(){
	Call_Aux_Map_Cube();

//left clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[3][i][j]=aux_cube[3][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][j][0]=aux_cube[5][2-j][2];

//front rotate	

	for(j=0;j<3;j++)
		cube[1][j][0]=aux_cube[0][j][0];

//bottom rotate	

	for(j=0;j<3;j++)
		cube[2][j][0]=aux_cube[1][j][0];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][j][2]=aux_cube[2][2-j][0];
}

void move_left1(){
	Call_Aux_Map_Cube();

//left anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[3][i][j]=aux_cube[3][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][j][0]=aux_cube[1][j][0];

//front rotate	

	for(j=0;j<3;j++)
		cube[1][j][0]=aux_cube[2][j][0];

//bottom rotate	

	for(j=0;j<3;j++)
		cube[2][j][0]=aux_cube[5][2-j][2];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][j][2]=aux_cube[0][2-j][0];
}

void move_top(){
	Call_Aux_Map_Cube();

//top clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[0][i][j]=aux_cube[0][2-j][i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		cube[1][0][j]=aux_cube[4][0][j];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][0][j]=aux_cube[1][0][j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][0][j]=aux_cube[5][0][j];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][0][j]=aux_cube[3][0][j];
}

void move_top1(){
	Call_Aux_Map_Cube();

//top anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[0][i][j]=aux_cube[0][j][2-i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		cube[1][0][j]=aux_cube[3][0][j];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][0][j]=aux_cube[5][0][j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][0][j]=aux_cube[1][0][j];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][0][j]=aux_cube[4][0][j];
}

void move_down(){
	Call_Aux_Map_Cube();

//top clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[2][i][j]=aux_cube[2][2-j][i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		cube[1][2][j]=aux_cube[3][2][j];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][2][j]=aux_cube[5][2][j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][2][j]=aux_cube[1][2][j];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][2][j]=aux_cube[4][2][j];
}

void move_down1(){
	Call_Aux_Map_Cube();

//top anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[2][i][j]=aux_cube[2][j][2-i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		cube[1][2][j]=aux_cube[4][2][j];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][2][j]=aux_cube[1][2][j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][2][j]=aux_cube[5][2][j];

//back rotate	

	for(j=0;j<3;j++)
		cube[5][2][j]=aux_cube[3][2][j];
}

void move_front(){
	Call_Aux_Map_Cube();

//front clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[1][i][j]=aux_cube[1][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][2][j]=aux_cube[3][2-j][2];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][j][2]=aux_cube[2][0][j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][j][0]=aux_cube[0][2][j];

//down rotate	

	for(j=0;j<3;j++)
		cube[2][0][j]=aux_cube[4][2-j][0];
		
}

void move_front1(){
	Call_Aux_Map_Cube();

//front anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[1][i][j]=aux_cube[1][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][2][j]=aux_cube[4][j][0];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][j][2]=aux_cube[0][2][2-j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][j][0]=aux_cube[2][0][2-j];

//down rotate	

	for(j=0;j<3;j++)
		cube[2][0][j]=aux_cube[3][j][2];
}

void move_back(){
	Call_Aux_Map_Cube();

//back clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[5][i][j]=aux_cube[5][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][0][j]=aux_cube[4][j][2];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][j][0]=aux_cube[0][0][2-j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][j][2]=aux_cube[2][2][2-j];

//down rotate	

	for(j=0;j<3;j++)
		cube[2][2][j]=aux_cube[3][j][0];
}

void move_back1(){
	Call_Aux_Map_Cube();

//back anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cube[5][i][j]=aux_cube[5][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		cube[0][0][j]=aux_cube[3][2-j][0];

//left rotate	

	for(j=0;j<3;j++)
		cube[3][j][0]=aux_cube[2][2][j];

//right rotate	

	for(j=0;j<3;j++)
		cube[4][j][2]=aux_cube[0][0][j];

//down rotate	

	for(j=0;j<3;j++)
		cube[2][2][j]=aux_cube[4][2-j][2];
}

void Print_Cube_pretty(){
	for(i=0;i<6;i++){
		printf("%dth block:\n\n",i+1);
		for(j=0;j<3;j++){
			printf("%dth line:\t",j+1);
			for(k=0;k<3;k++)
				printf("%d  ",cube[i][j][k]);
			printf("\n");
		}
	}
}

void Print_Cube(){
	char c[6]={'W','R','Y','G','B','O'},p[6]={'T','F','D','L','R','B'};
	for(i=0;i<6;i++){
		printf("%c:\t",p[i]);
		for(j=0;j<3;j++){
			for(k=0;k<3;k++)
				printf("%c",c[(cube[i][j][k])-1]);
		}
		printf("\n");
	}
	printf("\n");
}

void Print_Aux_Cube(){
	char c[6]={'W','R','Y','G','B','O'},p[6]={'T','F','D','L','R','B'};
	printf("aux_cube:\n");
	for(i=0;i<6;i++){
		printf("%c:\t",p[i]);
		for(j=0;j<3;j++){
			for(k=0;k<3;k++)
				printf("%c",c[(aux_cube[i][j][k])-1]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
// movement methods:
	
	
	
	return 0;
}

