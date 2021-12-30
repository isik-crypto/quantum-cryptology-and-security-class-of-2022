#include<stdio.h>
#include<stdlib.h>

/***********************************************************************************************************************************
Hamming[7,4] coding scheme

message is of 4 bits length and code word is of 7 bits lenght

G = | 1  1  1  0  0  0  0 |
    | 1  0  0  1  1  0  0 |                     
    | 0  1  0  1  0  1  0 |
    | 1  1  0  1  0  0  1 |	
************************************************************************************************************************************/ 

void encoding(char M[], char C[]){
	C[2] = M[0]; C[4] = M[1]; C[5] = M[2]; C[6] = M[3];
	C[0] = ((M[0]^M[1])^M[3]);
	C[1] = (M[0]^M[2])^M[3];
	C[3] = (M[1]^M[2])^M[3];	
		
	}
/**************************************************************************************************************************************
error() is a noisy channel which introduces exactly one error in the codeword
****************************************************************************************************************************************/
void error(char C[], char C1[]){
	unsigned int seed;  
	printf("enter seed value:\n");
	scanf("%u", &seed);
	srand(seed);
	int i = abs(rand())%7;
	
	C1[0] = C[0]; C1[1] = C[1]; C1[2] = C[2]; C1[3] = C[3]; C1[4] = C[4]; C1[5] = C[5]; C1[6] = C[6];
	C1[i] = abs((C1[i]+1)%2);
	}
	
/*****************************************************************************************************************************************
in the decoding part error correction has been done using parity check matrix and the position where one error has occured then that bit will be flipped to get the correct code word that has been transmitted

H = | 1  0  1  0  1  0  1 |
    | 0  1  1  0  0  1  1 |                     
    | 0  0  0  1  1  1  1 |  	

******************************************************************************************************************************************/
void decoding(char C1[], char M[]){
	char P[3], C[7];
	
	P[0] = ((C1[0]^C1[2])^C1[4])^C1[6];
	P[1] = ((C1[1]^C1[2])^C1[5])^C1[6];
	P[2] = ((C1[3]^C1[4])^C1[5])^C1[6];
	
	C[0] = C1[0]; C[1] = C1[1]; C[2] = C1[2]; C[3] = C1[3]; C[4] = C1[4]; C[5] = C1[5]; C[6] = C1[6];
	
	int i = (P[0]) + (P[1]*2) + (P[2]*4) -1;
	
	printf("position of the error in the recieved code word: %d \n", i);
	C[i] = abs((1+C[i])%2);
	
	M[0] = C[2]; M[1] = C[4]; M[2] = C[5]; M[3] = C[6]; 
	
	}		
void main(){
  char M[4], C[7], C1[7], M1[4], m;
  
  printf("enter a number between 0 and 15: ");
  scanf("%hhu", &m);
  printf("\n");
  
  for(int i=0; i<4; ++i){
  	M[i] = abs(m%2);
  	m = (m-M[i])/2;
  	}
  
  printf("message: \n");
  for(int i=0; i<4; ++i){
  	printf("%hhu ", M[i]);
  	}
  printf("\n");	
  
  encoding(M, C);
   printf("code word: \n");
   for(int i=0; i<7; ++i){
  	printf("%hhu ", C[i]);
  	}
  printf("\n");
  
  error(C, C1);
  printf("recieved word with 1 error: \n");
  for(int i=0; i<7; ++i){
  	printf("%hhu ", C1[i]);
  	}
  printf("\n");
  
  decoding(C1, M1);
  printf("decoded message: \n");
  for(int i=0; i<4; ++i){
  	printf("%hhu ", M1[i]);
  	}
  printf("\n");
  
  
  }	
	

