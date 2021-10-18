// Program to find the inverse of a square matrix, if it exists

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j,k,l,m,n,s,t=0,u=0;
   long double *A[n],*inv_A[n],*aug_A[n],e,f,*B;
	
	
	printf("Enter the order of the square matrix: ");
	scanf("%d",&n);
	m=2*n;
	
	// dynamically creating the matrices
	for(i=0;i<n;i++)
	{
	 A[i]=(long double*)malloc(n*sizeof(long double));        // for original matrix
	 inv_A[i]=(long double*)malloc(n*sizeof(long double));    // for it's inverse
	 aug_A[i]=(long double*)malloc(m*sizeof(long double));    // for it's augmented matrix
	}
	
	// taking input for the matrix
	printf("\nEnter the matrix elements row wise: \n");
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	  {
	    printf("A[%d][%d]: ",i,j);
	    scanf("%Lf",&A[i][j]);
	    printf("\n");
	  }
	}
	
	// printing the entered matrix  
	printf("The entered matrix A is: \n");
	for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
        {
            printf("%Lf\t",A[i][j]);
        }
        printf("\n");
	}
	printf("\n");
	
	// creating the augmented matrix
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	  {
	    aug_A[i][j]=A[i][j];
	    if(i!=j) 
	       aug_A[i][n+j] = 0; 
	    else 
	       aug_A[i][n+j] = 1;
	  }
	}
	
	// printing the augmented matrix
	printf("The augmented matrix of A is: \n");
	for(i=0;i<n;i++)
	{
        for(j=0;j<m;j++)
        {
            printf("%Lf\t",aug_A[i][j]);
        }
        printf("\n");
	}
	printf("\n");
	
	// finding the inverse of A
	
	for(i=0;i<n;i++)             // for columns
	{
	   for(j=i;j<n;j++)          // for rows
	   {
	      if(aug_A[j][i]!=0)
	      { 
		     e=aug_A[j][i];
		     t++;
		     
		     // exchanging the row if the pivot element is zero
		     if(j!=i)
		     {
				B=(long double*)malloc(m*sizeof(long double));
		        for(k=0;k<m;k++)
		        {
		            B[k]=aug_A[i][k];
		            aug_A[i][k]=aug_A[j][k];
		            aug_A[j][k]=B[k];
		        }
		        free(B);
		     }
		
		     // making the pivot element 1.		
		     for(k=i;k<m;k++)
		     {
		         aug_A[i][k]=(1.0/e)*aug_A[i][k];
		     }
		  
		     // eliminating all the elements except the pivot element in the ith column
		     for(l=0;l<n;l++)
		     {
		         if(l!=i)
		         {
		            f=-aug_A[l][i];
		  
		            for(k=0;k<m;k++)
		            {
		                aug_A[l][k]=aug_A[l][k]+(f*aug_A[i][k]);
		            }
		         }
		     }
		   }
	       if(t==1)
	       {
	           u++;
	           break;
	       }
	   }
	  if(t==0)
	  {
	     printf("Entered matrix is not invertible!\n");
	     break;
	  }
	  t=0; 
	}
	   
	// storing the inverse matrix
	if(u==n)
	{
	  for(i=0;i<n;i++)
	  {
	     for(j=0;j<n;j++)
	     {
	         inv_A[i][j]=aug_A[i][n+j];
	     }
	  }
	  
	  
	  // printing the inverse matrix
	  printf("The inverse matrix is: \n");
	  for(i=0;i<n;i++)
	  {
	     for(j=0;j<n;j++)
	     {
	         printf("%Lf\t",inv_A[i][j]);
	     }
	     printf("\n");
	  }
	  printf("\n");
	}
	
	for(int i=0;i<n;i++)
	{
	   free(A[i]);
       free(inv_A[i]);
       free(aug_A[i]);
	}
	   
    return 0;
}




