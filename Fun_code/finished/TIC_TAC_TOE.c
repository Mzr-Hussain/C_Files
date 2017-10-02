#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define two_players 2
#define computer 1
#define player_1_wins 1
#define player_2_wins 2
#define true  1
#define false 0

char board[3][3];
int Game_Over=false;
int computer_or_player;

void print_board();
void board_clear();
void print_instructions();
void take_input( int* , int* );
void take_input_cmp( int* , int* );
int  check_game_over();
int  board_full();
int  input_scan();
int  cmp_brain();

void main(){
	int index_i,index_j;
	char again=' ';
	printf("\n\nTIC-TAC-TOE\n\n");
	print_instructions();
	board_clear();
	print_board();
	if(computer_or_player == two_players){
		while(!Game_Over){
			if(!(board_full())){
				printf("\n\nPLAYER 1 TURN :");
				take_input( &index_i, &index_j);
				board[index_i][index_j]='x';
				print_board();
				Game_Over=check_game_over();
				if( Game_Over == false && board_full() == false){
					printf("\n\nPLAYER 2 TURN :");
					take_input( &index_i, &index_j);
					board[index_i][index_j]='0';
					print_board();
					Game_Over=check_game_over();
				}
			}
			else {
				printf("\n\n\tOOOOH ITS A DRAW!!\n");
				Game_Over =3;
			}
		}
		if(Game_Over == player_1_wins)
			printf("\n\n\tCONGRATULATION PLAYER 1!!\n\t\tYOU WIN\n");
		else if(Game_Over == player_2_wins)
			printf("\n\n\tCONGRATULATION PLAYER 2!!\n\t\tYOU WIN\n");
		printf("\n\nDO YOU WANT TO PLAY AGAIN? (Y/N) :\n");
		again = getch();
//		scanf("%c",&again);
		while(!( again=='y' || again=='Y' || again=='n' || again=='N' )){
			printf("INVALID INPUT!\n");
			printf("(Y/N): ");
			again = getch();
//			scanf("%c",&again);
		}
		if(again=='y' || again=='Y' )
			main();
	}
	else{
		//computer playes here
		while(!Game_Over){
			if(!(board_full())){
				printf("\n\nPLAYER 1 TURN :");
				take_input( &index_i, &index_j);
				board[index_i][index_j]='x';
				print_board();
				Game_Over=check_game_over();
				if( Game_Over == false && board_full() == false){
					printf("\n\nCOMPUTERS TURN :");
					take_input_cmp( &index_i, &index_j);
					board[index_i][index_j]='0';
					print_board();
					Game_Over=check_game_over();
				}
			}
			else {
				printf("\n\n\tOOOOH ITS A DRAW!!\n");
				Game_Over =3;
			}
		}
		if(Game_Over == player_1_wins)
			printf("\n\n\tCONGRATULATION PLAYER!!\n\t\tYOU WIN\n");
		else if(Game_Over == player_2_wins)
			printf("\n\n\tOOOOOH!! YOU LOOOOOOSE!!\n");
		printf("\n\nDO YOU WANT TO PLAY AGAIN? (Y/N) :\n");
		again = getch();
//		scanf("%c",&again);
		while(!( again=='y' || again=='Y' || again=='n' || again=='N' )){
			printf("INVALID INPUT!\n");
			printf("(Y/N): ");
			again = getch();
//			scanf("%c",&again);
		}
		if(again=='y' || again=='Y' )
			main();
	}
}

void print_board(){
	printf("\n\n");
	printf("\t\t\t   %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
	printf("\t\t\t  ---+---+---\n");
	printf("\t\t\t   %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
	printf("\t\t\t  ---+---+---\n");
	printf("\t\t\t   %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}

void board_clear(){	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			board[i][j]=' ';
	Game_Over = false;
}

void print_instructions(){
	static int first_time=true;
	if(first_time){
	printf("\nINSTRUCTIONS TO PLAY:\n\n");
	printf("The input method: enter a number from 1-9 to fill in te block (U are \'x\')\n");
	printf("when \'>\' is displayed ten input your choise\n");
	printf("\nFOR 1-PLAYER TYPE 1\nFOR 2-PLAYERS TYPE 2\n>\t");
	computer_or_player = getch()-'0';
	while(computer_or_player!=1 && computer_or_player!=2){
		printf("\nINVAVLID INPUT\t> ");
		computer_or_player = getch()-'0';
	}
	printf("\n\n\t\tLETS PLAY!!\n\n");
	first_time=false;
	}
}

void take_input(int* index_i,int* index_j){
	int in=0,i,j;
	printf(">\t");
	in=input_scan();
//	scanf("%d",&in);
repeat:	while(!(in>=1 && in<=9)){
			printf("INVALID INPUT!\n");
			printf(">\t");
			in=input_scan();
//			scanf("%d",&in);
		}
	if(in<=3)		{	i=0;j=in-1;	}
	else if(in<=6)	{	i=1;j=in-4;	}
	else			{	i=2;j=in-7;	}
	if(board[i][j]==' '){
		*index_i=i;
		*index_j=j;
	}
	else{
		in=0;
		goto repeat;
	}
}

void take_input_cmp(int* index_i,int* index_j){
	int in=0;
	printf(">\t");
	
	//FOR RANDOM CMP PERFORMANCE
	/*
	int i,j;
repeat:	in = (rand()%9)+1;
	if(in<=3)		{	i=0;j=in-1;	}
	else if(in<=6)	{	i=1;j=in-4;	}
	else			{	i=2;j=in-7;	}
	if(board[i][j]==' '){
		*index_i=i;
		*index_j=j;
		printf("%d\n",in);
	}
	else{
		in=0;
		goto repeat;
	}
	//*/
	
	// FOR NON RANDOM CMP PERFORMANCE
	
	//*
	cmp_brain( index_i, index_j );	//RETURNS THE VALUE AT WHICH IT NEEDS TO BE PLACED
	in=(3**index_i)+*index_j+1;
	printf("%d\n",in);
	//*/
}

int check_game_over(){
	int i,x0,x1,x2,o0,o1,o2,ret=0;
	x0=x1=x2=o0=o1=o2=0;
	for(i=0;i<3;i++){
		if		(board[0][i]=='x')	x0++;
		else if	(board[0][i]=='0')	o0++;
		if		(board[1][i]=='x')	x1++;
		else if	(board[1][i]=='0')	o1++;
		if		(board[2][i]=='x')	x2++;
		else if	(board[2][i]=='0')	o2++;
	}
	if( x0==3 || x1==3 || x2==3 )
		ret= player_1_wins;
	else if( o0==3 || o1==3 || o2==3 )
		ret= player_2_wins;
	x0=x1=x2=o0=o1=o2=0;
	for(i=0;i<3;i++){
		if		(board[i][0]=='x')	x0++;
		else if	(board[i][0]=='0')	o0++;
		if		(board[i][1]=='x')	x1++;
		else if	(board[i][1]=='0')	o1++;
		if		(board[i][2]=='x')	x2++;
		else if	(board[i][2]=='0')	o2++;
	}
	if( x0==3 || x1==3 || x2==3 )
		ret= player_1_wins;
	else if( o0==3 || o1==3 || o2==3 )
		ret= player_2_wins;
	x0=x1=x2=o0=o1=o2=0;
	for(i=0;i<3;i++){
		if		(board[i][i]=='x')		x0++;
		else if	(board[i][i]=='0')		o0++;
		if		(board[i][2-i]=='x')	x1++;
		else if	(board[i][2-i]=='0')	o1++;
	}
	if( x0==3 || x1==3  )
		ret= player_1_wins;
	else if( o0==3 || o1==3 )
		ret= player_2_wins;
	
	return ret;
}

int board_full(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(board[i][j]==' ')
				return false;
	return true;
}

int  input_scan(){
	int in;
	char input;
	input = getch();
	in=input-'0';
	return in;
}

int cmp_brain( int *index_i, int *index_j){
	int hor=0,ver=0,dig1=0,dig2=0,i,j;
	*index_i = -1;
	*index_j = -1;
	for(i=0;i<3;i++){
		hor=0;
		ver=0;
		for(j=0;j<3;j++){
			if(board[i][j]=='x'){
				hor++;
				if(hor==2) goto exit_loop1;
			}
			if(board[j][i]=='x'){
				ver++;
				if(ver==2) goto exit_loop1;
			}
		}
	}
	exit_loop1:
	if(hor==2){
		if( (j==1) && (board[i][2]==' ') ){
			*index_i = i;
			*index_j = 2;
		}
		else if(j==2){
			if(board[i][0]==' '){
				*index_i = i;
				*index_j = 0;
			}
			else if(board[i][1]==' '){
				*index_i = i;
				*index_j = 1;
			}
		}
	}
	if(ver==2){
		if( (j==1) && (board[2][i]==' ') ){
			*index_i = 2;
			*index_j = i;
		}
		else if(j==2){
			if(board[0][i]==' '){
				*index_i = 0;
				*index_j = i;
			}
			else if(board[1][i]==' '){
				*index_i = 1;
				*index_j = i;
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if((i==j) && (board[i][j]=='x')){
				dig1++;
				if(dig1==2) goto exit_loop2;
			}
			if((i==2-j) && (board[i][j]=='x')){
				dig2++;
				if(dig2==2) goto exit_loop2;
			}
		}
	}
	exit_loop2:
	if( (dig1==2) && (*index_i ==-1 || *index_j==-1) ){
		if(board[0][0]==' '){
			*index_i = 0;
			*index_j = 0;
		}
		else if(board[1][1]==' '){
			*index_i = 1;
			*index_j = 1;
		}
		else if(board[2][2]==' '){
			*index_i = 2;
			*index_j = 2;
		}
	}
	if( (dig2==2) && (*index_i ==-1 || *index_j==-1) ){
		if(board[0][2]==' '){
			*index_i = 0;
			*index_j = 2;
		}
		else if(board[1][1]==' '){
			*index_i = 1;
			*index_j = 1;
		}
		else if(board[2][0]==' '){
			*index_i = 2;
			*index_j = 0;
		}
	}
	if( *index_i ==-1 || *index_j==-1 ){
			//*
			int i,j,in;
repeat2:	in = (rand()%9)+1;
			if(in<=3)		{	i=0;j=in-1;	}
			else if(in<=6)	{	i=1;j=in-4;	}
			else			{	i=2;j=in-7;	}
			if(board[i][j]==' '){
				*index_i = i;
				*index_j = j;
			}
			else{
				in=0;
				goto repeat2;
			}
			//*/
	}		
}
