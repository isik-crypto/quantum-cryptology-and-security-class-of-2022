#include<stdio.h>
#include<math.h>

int main()
{   
    int i,j,n,p,pos,q;
    float A[10][10], I[10][10];
    float max,temp;
    
    printf("\nEnter the size of the matrix : ");
    scanf("%d", &n);
    printf("\nEnter the elements of the matrix \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f", &A[i][j]);
            
    for(i=0; i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                I[i][j]=1 ;
            else
                I[i][j]=0;
        }
    }
    
    printf("\n\n");
    

    
    for(i=0;i<n-1;i++)
    {
        max = fabs(A[i][i]);
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(max < fabs(A[j][i]))
            {
                max= fabs(A[j][i]);
                pos=j;
            }
        }
    if(pos-i >0)
    {
        for(p=0;p<n;p++){
            
            temp= A[pos][p];
            A[pos][p]=A[i][p];
            A[i][p]=temp;
            
            temp= I[pos][p];
            I[pos][p]=I[i][p];
            I[i][p]=temp;
            
        }
        printf("\n\n");
     }
    }
    

    printf("\n\n");
    max= 0;
    pos = 0;
    
    float factor;
    int k=0;
    
    for(j=0;j<n;j++)
    {
        if(A[k][k] !=0)
            A[k][j] = A[k][j]/A[k][k];
        for(i=0;i<n;i++)
        {
            if(i!=k)
            {
                if(A[k][k] != 0)
                {
                    factor = A[i][k]/A[k][k] ;
                    for(p=0;p<n;p++)
                    {
                        A[i][p] = A[i][p] - factor * A[k][p];
                        I[i][p] = I[i][p] - factor * I[k][p];   
                    }
                }
             }
        }
            k=k+1;
            
     } 
       
        float c=1;
        for(i=0;i<n;i++)
            c= c* A[i][i]; 
            
        if(c==0)
            printf("\n The matrix is singular\n");
        
        else
        {
            printf("\n");
            printf("\n reduced form:\n");
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    printf("%0.2f  |",A[i][j]);
                }
            printf("\n");
            }
            printf("\n\nThe inverse is :\n");
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    printf("%0.2f  |",I[i][j]);
                }
            printf("\n");
            }
        } 
            
    return 0;

}


