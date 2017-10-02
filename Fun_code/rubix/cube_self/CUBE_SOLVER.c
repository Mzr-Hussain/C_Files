#include <stdio.h>
#define true 1
#define false 0
#define front 0
#define top 1
#define back 2
#define bottom 3
#define left 4
#define right 5
#define mid 4

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

#define aux1=cube equal_aux_real();

char cube[6][9];
char aux1_cube[6][3][3],aux_[6][3][3];
char result[40];

int  check_correct_input();
void print_intro();
int  assign_numerics( char );
int  aux1_cube_finish();
void solve_cube();
void call_aux_map_cube();
void move_right();
void move_righ1();
void move_left();
void move_left1();
void move_back();
void move_back1();
void move_front();
void move_front1();
void move_top();
void move_top1();
void move_down();
void move_down1();
void equal_aux_real();

void main(){
	int check;
	print_intro();
	printf("\nENTER THE FRONT LAYER OF CUBE:\n");
	scanf("%s",&cube[front]);
	printf("\nENTER THE TOP LAYER OF CUBE:\n");
	scanf("%s",&cube[top]);
	printf("\nENTER THE BACK LAYER OF CUBE:\n");
	scanf("%s",&cube[back]);
	printf("\nENTER THE BOTTOM LAYER OF CUBE:\n");
	scanf("%s",&cube[bottom]);
	printf("\nENTER THE LEFT LAYER OF CUBE:\n");
	scanf("%s",&cube[left]);
	printf("\nENTER THE RIGHT LAYER OF CUBE:\n");
	scanf("%s",&cube[right]);
	check = check_correct_input();
	if(check == true){									//RED =0  BLUE=1  GREEN=2  ORANGE=3  WHITE=4  YELLOW=5
		while(!(aux1_cube_finish()))
			solve_cube();
	}
	else
		printf("\nINVALID INPUT\n\n");
	printf("\n\nWANT TO TRY AGAIN (Y/N) : ");
	int again =take_input();
	if(again == true)	main();
	printf("\n\nTHANK YOU...");
}

int check_correct_input(){
	int r,b,g,o,w,y=0;
	r=b=g=o=w=y=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<9;j++){
			if( cube[i][j]=='R' || cube[i][j]=='r' )
				r++;
			else if( cube[i][j]=='B' || cube[i][j]=='b' )
				b++;
			else if( cube[i][j]=='G' || cube[i][j]=='g' )
				g++;
			else if( cube[i][j]=='O' || cube[i][j]=='o' )
				o++;
			else if( cube[i][j]=='W' || cube[i][j]=='w' )
				w++;
			else if( cube[i][j]=='Y' || cube[i][j]=='y' )
				y++;
		}
	}
	if(r==b==g==o==w==y==9)
		return true;
	else
		return false;
}

void print_intro(){
	static int flag = false;
	printf("WELCOME TO CUBE SOLVER \nTHIS IS A 3X3 CUBE SOLVER JUST INPUT IN THE COLORS ON EACH LAYER\n\n");
	printf("*---+---+---*\n");
	printf("| * | * | * |\n");
	printf("|---|---|---|\n");
	printf("| * | * | * |\n");
	printf("|---|---|---|\n");
	printf("| * | * | * |\n");
	printf("*---+---+---*\n");
	printf("\n\n");
}

int assign_numerics( char middle ){
	if( middle == 'R' || middle == 'r' )
		return 0;
	else if( middle == 'B' || middle == 'b' )
		return 1;
	else if( middle == 'G' || middle == 'g' )
		return 2;
	else if( middle == 'O' || middle == 'o' )
		return 3;
	else if( middle == 'W' || middle == 'w' )
		return 4;
	else if( middle == 'Y' || middle == 'y' )
		return 5;
}

int aux1_cube_finish(){
	char middle[6];
	int flag=true;
	for(int i=0;i<6;i++)
		middle=cube[i][mid];
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(middle[i]!=aux1_cube[i][j][k]){
					flag=false;
					break;
				}
			}
		}
	}
	return flag;
}

void solve_cube(){
	// the main metod of solving cube
	//brutal force
	static int total_moves=1;
	int i=1;
	while( i<=total_moves ){
		for(int j=0;j<i;j++){
			
		}
	}
}

void call_aux_map_cube(){
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++)
				aux_cube[i][j][k]=aux1_cube[i][j][k];
		}
	}
}

void move_right(){
	call_aux_map_cube();

//right clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[4][i][j]=aux_cube[4][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][j][2]=aux_cube[1][j][2];

//front rotate	

	for(j=0;j<3;j++)
		aux1_cube[1][j][2]=aux_cube[2][j][2];

//bottom rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][j][2]=aux_cube[5][2-j][0];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][j][0]=aux_cube[0][2-j][2];
}

void move_right1(){
	call_aux_map_cube();

//right anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[4][i][j]=aux_cube[4][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][j][2]=aux_cube[5][2-j][0];

//front rotate	

	for(j=0;j<3;j++)
		aux1_cube[1][j][2]=aux_cube[0][j][2];

//bottom rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][j][2]=aux_cube[1][j][2];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][j][0]=aux_cube[2][2-j][2];
}

void move_left(){
	call_aux_map_cube();

//left clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[3][i][j]=aux_cube[3][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][j][0]=aux_cube[5][2-j][2];

//front rotate	

	for(j=0;j<3;j++)
		aux1_cube[1][j][0]=aux_cube[0][j][0];

//bottom rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][j][0]=aux_cube[1][j][0];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][j][2]=aux_cube[2][2-j][0];
}

void move_left1(){
	call_aux_map_cube();

//left anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[3][i][j]=aux_cube[3][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][j][0]=aux_cube[1][j][0];

//front rotate	

	for(j=0;j<3;j++)
		aux1_cube[1][j][0]=aux_cube[2][j][0];

//bottom rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][j][0]=aux_cube[5][2-j][2];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][j][2]=aux_cube[0][2-j][0];
}

void move_top(){
	call_aux_map_cube();

//top clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[0][i][j]=aux_cube[0][2-j][i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		aux1_cube[1][0][j]=aux_cube[4][0][j];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][0][j]=aux_cube[1][0][j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][0][j]=aux_cube[5][0][j];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][0][j]=aux_cube[3][0][j];
}

void move_top1(){
	call_aux_map_cube();

//top anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[0][i][j]=aux_cube[0][j][2-i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		aux1_cube[1][0][j]=aux_cube[3][0][j];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][0][j]=aux_cube[5][0][j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][0][j]=aux_cube[1][0][j];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][0][j]=aux_cube[4][0][j];
}

void move_down(){
	call_aux_map_cube();

//top clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[2][i][j]=aux_cube[2][2-j][i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		aux1_cube[1][2][j]=aux_cube[3][2][j];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][2][j]=aux_cube[5][2][j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][2][j]=aux_cube[1][2][j];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][2][j]=aux_cube[4][2][j];
}

void move_down1(){
	call_aux_map_cube();

//top anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[2][i][j]=aux_cube[2][j][2-i];
	}
	
//front rotate

	for(j=0;j<3;j++)
		aux1_cube[1][2][j]=aux_cube[4][2][j];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][2][j]=aux_cube[1][2][j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][2][j]=aux_cube[5][2][j];

//back rotate	

	for(j=0;j<3;j++)
		aux1_cube[5][2][j]=aux_cube[3][2][j];
}

void move_front(){
	call_aux_map_cube();

//front clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[1][i][j]=aux_cube[1][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][2][j]=aux_cube[3][2-j][2];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][j][2]=aux_cube[2][0][j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][j][0]=aux_cube[0][2][j];

//down rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][0][j]=aux_cube[4][2-j][0];
		
}

void move_front1(){
	call_aux_map_cube();

//front anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[1][i][j]=aux_cube[1][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][2][j]=aux_cube[4][j][0];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][j][2]=aux_cube[0][2][2-j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][j][0]=aux_cube[2][0][2-j];

//down rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][0][j]=aux_cube[3][j][2];
}

void move_back(){
	call_aux_map_cube();

//back clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[5][i][j]=aux_cube[5][2-j][i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][0][j]=aux_cube[4][j][2];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][j][0]=aux_cube[0][0][2-j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][j][2]=aux_cube[2][2][2-j];

//down rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][2][j]=aux_cube[3][j][0];
}

void move_back1(){
	call_aux_map_cube();

//back anti-clock rotate

	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			aux1_cube[5][i][j]=aux_cube[5][j][2-i];
	}
	
//top rotate

	for(j=0;j<3;j++)
		aux1_cube[0][0][j]=aux_cube[3][2-j][0];

//left rotate	

	for(j=0;j<3;j++)
		aux1_cube[3][j][0]=aux_cube[2][2][j];

//right rotate	

	for(j=0;j<3;j++)
		aux1_cube[4][j][2]=aux_cube[0][0][j];

//down rotate	

	for(j=0;j<3;j++)
		aux1_cube[2][2][j]=aux_cube[4][2-j][2];
}

void equal_aux_real(){
	aux1_cube
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			aux1_cube[i][j/3][j%3]=cube[i][j];
		}
	}
}