#include<stdio.h>
#include<stdlib.h>

int main(){
	
	long double** A, **C,**I, **A_aug;
	int m,n,i,j,k, singular = 0, decider=1;
	
	printf("enetr the dimension of the square matrix: \n");
	scanf("%d", &m);
	n = 2*m;
	A = (long double**) malloc(m * sizeof(long double*));
	I = (long double**) malloc(m * sizeof(long double*));
	C = (long double**) malloc(m * sizeof(long double*));
	A_aug = (long double**) malloc(m * sizeof(long double*));
	
	for(int i = 0; i < m; ++i){
	  A[i]= (long double*) malloc(m * sizeof(long double));
	  C[i]= (long double*) malloc(m * sizeof(long double));
	  I[i] = (long double*) malloc(m * sizeof(long double));
	  A_aug[i] = (long double*) malloc(n * sizeof(long double));
	    	}
		
	printf("eneter the m*m matrix: \n");
	
	for(int i = 0; i < m; ++i){
	  for(j = 0; j < m; ++j){
	    printf("A[%d][%d]: ", i, j);
	    scanf("%LF", &A[i][j]);
		}
	  }
	  
	/* printing matrix A*/
	printf("Matrix A you have entered: \n");
	for(int i = 0; i < m; ++i){
          for(int j = 0; j < m; ++j){
            printf("%LF\t", A[i][j]);
              }
          printf("\n");
    	  }
    		
	printf("\n");
	
	/*matrix inversion */
	
	// Augmenting A with I denote it as A_aug.		
	for(int i = 0; i < m; ++i){
	  for(int j = 0; j < m; ++j){
	    A_aug[i][j] = A[i][j];
	    if(i != j){ I[i][j] = 0; }
	    else I[i][j] = 1;
	    A_aug[i][m+j] = I[i][j];
	      }
	    }
	
	/* printing matrix A_aug*/
	printf("Matrix A augmented with I: \n");
	for(int i = 0; i < m; ++i){
          for(int j = 0; j < n; ++j){
            printf("%LF\t", A_aug[i][j]);
              }
          printf("\n");
    	  }
    		
	printf("\n");    
	
	
	for( j = 0; j < m; ++j){
	  i = j;
	   
	    for( k = i; k < m; ++k){
	      
	      if(A_aug[k][i] != 0){ 
		long double p = A_aug[k][i];
		singular = singular + 1;
		if(k != i){
		  // row exchange A_aug[i] with A_aug[k]
		
		  long double* T;
				
		  T = (long double*) malloc(n * sizeof(long double));
		  for(int l = 0; l < n; ++l){
		    T[l] = A_aug[i][l];
		    A_aug[i][l] = A_aug[k][l];
		    A_aug[k][l] = T[l];
		      }
		  free(T);
		  //so after this step T = A_aug[i], A_aug[i] = A_aug[k], A_aug[k] = T
		  }
		
		//scalar maultiplication for making pivot as 1.		
		for(int l = i; l < n; ++l){
		  A_aug[i][l] = (1.0/p)*A_aug[i][l];
		  }
		  
		// eleminating elements below A_aug[i][i] != 0
		for(int q = 0; q < m; ++q){
		  if(q != i){
		  long double p = -A_aug[q][i];
		  //row additions
		  for(int l =0; l < n; ++l){
		    A_aug[q][l] = A_aug[q][l] + (p*A_aug[i][l]);
		    }
		    }
		  }
		}
	        if(singular == 0){
	          decider = 0; 
	          break;
	          }
	        }
	        if(decider == 0){printf("Matrix A you have entered is Singular\n");
	          break;
	          }
	        singular = 0;  
	       }
	      	
	//inverse of A is C
	if(decider !=0){
	for(i = 0; i < m; ++i){
	  for(j = 0; j < m; ++j){
	    C[i][j] = A_aug[i][m+j];
	    }
	  }
	  }	
	free(A_aug);
	
	//printing inverse	  
	if(decider !=0){
	printf("Matrix inverse: \n");
	for(int i = 0; i < m; ++i){
          for(int j = 0; j < m; ++j){
            printf("%LF\t", C[i][j]);
              }
          printf("\n");
    	  }
    	  }
    		
	printf("\n");
	
	//checking
	if(decider !=0){
	printf("verification: \n");
	for(i = 0; i < m; ++i){
	  for(j = 0; j < m; ++j){
	    I[i][j] = 0;
	    for(k = 0; k < m; ++k){
	      I[i][j] = I[i][j] + A[i][k] * C[k][j];
	      }
	    printf("%LF\t ", I[i][j]);  
	    }
	    printf("\n");
	  }
	  }
	  free(A);
	  free(C);
	  free(I);
	
	return 0;
	}
