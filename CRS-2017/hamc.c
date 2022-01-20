#include <stdio.h>

void main()
{
    int code[10];
    int i;

    printf("Enter 4 bits of data one after another\n");
    scanf("%d",&code[0]);
    scanf("%d",&code[1]);
    scanf("%d",&code[2]);
    scanf("%d",&code[3]);

    //Calculation of even parity
    code[6]=code[0]^code[2]^code[3];
    code[5]=code[0]^code[1]^code[3];
    code[4]=code[0]^code[1]^code[2];
 
printf("\nEncoded data is\n");
for(i=0;i<7;i++)
        printf("%d ",code[i]);
}