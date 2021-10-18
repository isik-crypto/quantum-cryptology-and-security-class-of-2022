//Swagata Sasmal, crs2024
//Corrections are yet to be made
#include <stdio.h>
#include<math.h>

int main()
{   
    int i,j,n,p,pos,q;
    float A[10][10], I[10][10];
    float max,temp;
    
    printf("\nEnter the size of the matrix : ");
    scanf("%d", &n);
    printf("\nEnter the elements of the matrix \n");
    
    //Taking the input of the matrix whose inverse is to be computed, is exists
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f", &A[i][j]);
    
    //Storing the identity matrix in I
    for(i=0; i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                I[i][j]=1 ;
            else
                I[i][j]=0;
        }
    }
    
    printf("\n\n");
    
    //Setting the maximum in each column to be the pivot element, by making row swaps 
    
    for(i=0;i<n-1;i++){
        max = fabs(A[i][i]);
        pos=i;
        for(j=i+1;j<n;j++){
            if(max < fabs(A[j][i])){
                max= fabs(A[j][i]);
                pos=j;
            }
        }
    if(pos-i >0){
        
        //swapping the rows of A and I
        for(p=0;p<n;p++){
            
            temp= A[pos][p];
            A[pos][p]=A[i][p];
            A[i][p]=temp;
            
            temp= I[pos][p];
            I[pos][p]=I[i][p];
            I[i][p]=temp;
            
        }
        printf("\n\n");
        /* Debug output
        for(p=0;p<n;p++){
            for(q=0;q<n;q++){
                printf("%0.2f  |",A[p][q]);
            }
            printf("\n");}
        
        printf("\n\n");
        for(p=0;p<n;p++){
                for(q=0;q<n;q++){
                    printf("%0.2f  |",I[p][q]);
            }
            printf("\n");
    }*/
        
    }
    }
    

    printf("\n\n");
    max= 0;
    pos = 0;
    
    float factor;
    int k=0;
    
    //Row operations to reduce to echelon form and performing those same operations on I to get the inverse
    for(j=0;j<n;j++){
        if(A[k][k] !=0)
            A[k][j] = A[k][j]/A[k][k];
        for(i=0;i<n;i++){
            if(i!=k){
                if(A[k][k] != 0){
                    factor = A[i][k]/A[k][k] ;
                    for(p=0;p<n;p++){
                        A[i][p] = A[i][p] - factor * A[k][p];
                        I[i][p] = I[i][p] - factor * I[k][p];
                        
                    }}
                }
            }
            k=k+1;
            
            } 
       
        float c=1;
        for(i=0;i<n;i++)
            c= c* A[i][i]; 
            
            
        //In row echelon form, if the product of the diagonal elements is 0, then the matrix is singular
        if(c==0)
            printf("\n The matrix is singular\n");
        
        else{
            printf("\n");
            // The reduced form will be the identity matrix when the matrix is invertible
            printf("\n reduced form:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    printf("%0.2f  |",A[i][j]);
            }
            printf("\n");
        }
            printf("\n\nThe inverse is :\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    printf("%0.2f  |",I[i][j]);
        }
            printf("\n");
        }} 
            
    return 0;

}


