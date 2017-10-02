#include<stdio.h>
#include<string.h>
#define max_length 20
	char letters[28][62]={"   AAAA   \n  A    A  \n  AAAAAA  \n  A    A  \n  A    A  \n\n", // A //28 with 62 in one
					      "  BBBBBB  \n  B     B \n  BBBBBB  \n  B     B \n  BBBBBB  \n\n", // B 
      					  "   CCCCC  \n  C       \n  C       \n  C       \n   CCCCC  \n\n", // C 
	    				  "  DDDDD   \n  D    D  \n  D    D  \n  D    D  \n  DDDDD   \n\n", // D 
		    			  "  EEEEEE  \n  E       \n  EEEEEE  \n  E       \n  EEEEEE  \n\n", // E 
   			    		  "  FFFFFF  \n  F       \n  FFFFF   \n  F       \n  F       \n\n", // F 
				    	  "   GGGGG  \n  G       \n  G GGGG  \n  G    G  \n   GGGG   \n\n", // G 
					      "  H    H  \n  H    H  \n  HHHHHH  \n  H    H  \n  H    H  \n\n", // H 
    					  "  IIIIIII \n     I    \n     I    \n     I    \n  IIIIIII \n\n", // I 
	    				  "  JJJJJJJ \n     J    \n     J    \n  J  J    \n   JJ     \n\n", // J 
		    			  "  K   K   \n  K  K    \n  KKK     \n  K  K    \n  k   k   \n\n", // K 
			    		  "  L       \n  L       \n  L       \n  L       \n  LLLLLL  \n\n", // L 
				    	  "  M    M  \n  MM  MM  \n  M MM M  \n  M    M  \n  M    M  \n\n", // M 
						  "  N    N  \n  NN   N  \n  N N  N  \n  N  N N  \n  N   NN  \n\n", // N 
						  "   OOOO   \n  O    O  \n  O    O  \n  O    O  \n   OOOO   \n\n", // O 
						  "  PPPPP   \n  P    P  \n  PPPPP   \n  P       \n  P       \n\n", // P 
						  "   QQQQ   \n  Q    Q  \n  Q Q  Q  \n  Q  Q Q  \n   QQQQ   \n\n", // Q 
						  "  RRRRR   \n  R    R  \n  RRRRR   \n  R   R   \n  R    R  \n\n", // R 
						  "   SSSSS  \n  S       \n   SSSS   \n       S  \n  SSSSS   \n\n", // S 
						  "  TTTTTTT \n     T    \n     T    \n     T    \n     T    \n\n", // T 
						  "  U    U  \n  U    U  \n  U    U  \n  U    U  \n   UUUU   \n\n", // U 
						  "  V    V  \n  V    V  \n  V    V  \n   V  V   \n    VV    \n\n", // V 
						  "  W    W  \n  W    W  \n  W WW W  \n  WW  WW  \n  W    W  \n\n", // W 
						  "  X    X  \n   X  X   \n    XX    \n   X  X   \n  X    X  \n\n", // X 
						  "  Y    Y  \n   Y  Y   \n    YY    \n    YY    \n    YY    \n\n", // Y 
					 	  "  ZZZZZZ  \n      Z   \n     Z    \n    Z     \n  ZZZZZZ  \n\n", // Z 
						  "          \n          \n          \n          \n          \n\n", // space    //32 [space]
						  "----..----\n"};                                                  // period

void print_hori(char in[max_length],int n){
	int i,j,k;
	for(i=0;i<45;i+=11){
		for(j=0;j<n;j++){
			for(k=0;k<10;k++)
				(in[j]>=97 && in[j]<=122)? printf("%c",letters[in[j]-97][i+j+k]): printf(".");
				printf("  ");
		}
		printf("\n");
	}
	
}

void print_verti(char c){
	int i,j;
	if(c>=97 && c<=122){
		for(i=0;i<45;i+=11){
			for(j=0;j<10;j++)
				printf("%c",letters[c-97][i+j]);
			printf("\n");
		}
	}
	else if(c>=65 && c<=90){
		for(i=0;i<45;i+=11){
			for(j=0;j<10;j++)
				printf("%c",letters[c-65][i+j]);
			printf("\n");
		}
	}
}

int main(){
	char in[max_length];
	int n,i;				  
 	while(1){
	 	printf("Enter any sentense:\n");
	 	scanf ("%[^\n]%*c",in);
	 	
	 	//for vertical
	 	
	 	n=strlen(in);
//	 	printf("\nvertcal:\n");
//	 	for(i=0;i<n;i++){
//	 		print_verti(in[i]);
//			printf("\n");
//	 	}
	 	
	 	//for horizontal
	 	
//	 	printf("\nhorizotal:\n");
		print_hori(in,n);
 	}
	return 0;
}
