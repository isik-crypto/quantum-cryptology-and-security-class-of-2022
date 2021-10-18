
#include <stdio.h>
#include<stdlib.h>

int main()
{
   int i,j,k,l,m,n,s ,flag = 0, temp = 0;
   long double *M[n], *N[n], *aug_M[n], e, f, *P;
	
	
	printf("Enetr the dimension of the square matrix: ");
	scanf("%d", &n);
	m = 2*n;
	
	for(i = 0; i < n; i++){
	 M[i] = (long double*)malloc(n * sizeof(long double));
	 N[i] = (long double*)malloc(n * sizeof(long double));
	 aug_M[i] = (long double*)malloc(m * sizeof(long double));
	}
	
	//Input matrix
	printf("Please enter the matrix to get its inverse: \n");
	for(int i = 0; i < n; i++){
	  for(j = 0; j < n; j++){
	    printf("M[%d][%d]: ", i, j);
	    scanf("%Lf", &M[i][j]);
	    printf("\n");
	  }
	}
	
	//Print the input matrix  
	printf("Entered matrix: \n");
	for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%Lf\t", M[i][j]);
        }
        printf("\n");
	}
	printf("\n");
	
	//Constructing augmented matrix of the input matrix
	for( i = 0; i < n; i++){
	  for( j = 0; j < n; j++){
	    aug_M[i][j] = M[i][j];
	    if(i != j) aug_M[i][n+j] = 0; 
	    else aug_M[i][n+j] = 1;
	  }
	}
	
	//Print augmented matrix
	printf("Augmented matrix of M: \n");
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%Lf\t", aug_M[i][j]);
        }
        printf("\n");
	}
	printf("\n");
	
	//Calculating inverse matrix
	
	for( i = 0; i < n; i++){
	   for( j = i; j < n; j++){
	      if(aug_M[j][i] != 0){ 
		     e = aug_M[j][i];
		     flag = flag + 1;
		     
		     //Exchanging the row if the pivot element is zero
		     if(j != i){
				P = (long double*) malloc(m * sizeof(long double));
		        for(k = 0; k < m; k++){
		            P[k] = aug_M[i][k];
		            aug_M[i][k] = aug_M[j][k];
		            aug_M[j][k] = P[k];
		        }
		        free(P);
		     }
		
		     //Making pivot element as 1.		
		     for(k = i; k < m; k++){
		         aug_M[i][k] = (1.0/e)*aug_M[i][k];
		     }
		  
		     //Eleminating elements below the pivot elements
		     for(l = 0; l < n; l++){
		         if(l != i){
		            f = -aug_M[l][i];
		  
		            for(k = 0; k < m; k++){
		                aug_M[l][k] = aug_M[l][k] + (f*aug_M[i][k]);
		            }
		         }
		     }
		   }
	       if(flag == 1){
	           temp++;
	           break;
	       }
	   }
	  if(flag == 0){
	     printf("Input matrix is not invertible!\n");
	     break;
	  }
	  flag = 0; 
	}
	   
	//Inverse matrix
	if(temp == n){
	  for(i = 0; i < n; i++){
	     for(j = 0; j < n; j++){
	         N[i][j] = aug_M[i][n+j];
	     }
	  }
	  
	  
	  //Printing inverse matrix
	  printf("Inverse matrix: \n");
	  for(i = 0; i < n; i++){
	     for(j = 0; j < n; j++){
	         printf("%Lf\t", N[i][j]);
	     }
	     printf("\n");
	  }
	  printf("\n");
	}
	
	for (int i = 0; i < n; i++) free(M[i]);
    for (int i = 0; i < n; i++) free(N[i]);
    for (int i = 0; i < n; i++) free(aug_M[i]);
    return 0;
}





