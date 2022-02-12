#include<stdio.h>
#include<stdlib.h>
unsigned long int power(unsigned long long g, unsigned long long n, unsigned long long x)
{
	unsigned long long r=1;
	for(int i=0; i<32; ++i)
	{
		unsigned long int b= x&(1<<(64-i-1));
		if(b==0)
			r = (r*r)%n;
		else 
			r = (((r*r)%n)*g)%n;
	}
	return r;
}
int main()
{
	unsigned long  int p= 2147483659,g=1543932468,x,y,Ak,Bk,Ak1,Bk1,z,r,r1,z1;
	unsigned int seed1,seed2;  
	printf("enterthe seed for Alice value:\n");
	scanf("%u", &seed1);
	srand(seed1);
	x=rand()%p;
	printf("enterthe seed for Alice value:\n");
	scanf("%u", &seed2);
	srand(seed2);
	y=rand()%p;
	printf("x=%lu,y= %lu\n",x,y);
	Ak=power(g,p,x);
	Bk=power(g,p,y);
	printf("g^x=%lu,g^y= %lu\n",Ak,Bk);
	Ak1=power(Bk,p,x);
	Bk1=power(Ak,p,y);
	z=(x*y)%p;
	z1=x*y;
	r=power(g,z,p);
	printf("g^xy=%lu\n",r);
	
	printf("Key for Alice=%lu,Key for Bob= %lu\n",Ak1,Bk1);	
}
