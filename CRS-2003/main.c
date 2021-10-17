/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void main()
{
    double x;
    printf ("Enter the value between 0 and 100 , x= ");
    scanf ("%lf", &x);
   /* line16:
    {
        while (x < 0 || x > 100)
    {
        printf ("Please enter the number in the given range , x= ");
        scanf ("%lf", &x);
    }*/
    if (x >= 90 && x <= 100) printf("Grade is A+ \n");
    else if (x >= 80 && x < 90) printf("Grade is A \n");
    else if (x >= 70 && x < 80) printf("Grade is B+ \n");
    else if (x >= 60 && x < 70) printf("Grade is B \n");
    else if (x >= 50 && x < 60) printf("Grade is C+ \n");
    else if (x >= 40 && x < 50) printf("Grade is C \n");
    else if (x >= 30 && x < 40) printf("Grade is D+ \n");
    else if (x >= 20 && x < 30) printf("Grade is D \n");
    else if (x >= 10 && x < 20) printf("Grade is E+ \n");
    else if (x > 0 && x < 10) printf("Grade is E \n");
    else  printf("Grade is F\n");
    /*}
    
    printf ("Please enter the number in the given range if you want to check again , x= ");
    scanf ("%lf", &x);
    goto line16;*/
    

    
}
