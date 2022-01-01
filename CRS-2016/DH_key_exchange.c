#include<stdio.h>
#include<stdlib.h>

unsigned long long power(unsigned long long g, unsigned long long x, unsigned long long N){
			unsigned long long r=1;
			
			for(int i=0; i<64; ++i){
			  unsigned long long b = x&1;
			  if(b == 1){
			    r = (r*g)%N;
			    }
			  x = x >>1;
			  g = (g*g)%N;  
			  }
			return r;
			}
void Alice(unsigned long long g, unsigned long long N, unsigned long long ra1[]){
			
			unsigned int seed;  
			printf("enter seed value:\n");
			scanf("%u", &seed);
			srand(seed);
			unsigned long long x = abs(rand())%N;
			ra1[0] = x;
			ra1[1] = power(g, x, N);
			
			
			}			

void Bob(unsigned long long g, unsigned long long N, unsigned long long rb1[]){
			unsigned long long r[2];
			unsigned int seed;  
			printf("enter seed value:\n");
			scanf("%u", &seed);
			srand(seed);
			unsigned long long y = abs(rand())%N;
			rb1[0] = y;
			rb1[1] = power(g, y, N);
			
			}
unsigned long long Alice1(unsigned long long g, unsigned long long h, unsigned long long x, unsigned long long N){
			unsigned long long r;
			r = power(h, x, N);
			return r;				
			}						

unsigned long long Bob1(unsigned long long g, unsigned long long h, unsigned long long y, unsigned long long N){
			unsigned long long r;
			r = power(h, y, N);
			return r;				
			}
int main(){
   /*  gp pari code for generating a 64 bit prime 
   ? p = nextprime(2^63);
? digits(p, 2^32)
%8 = [2147483648, 29]
? p
%9 = 9223372036854775837

   */
   
   /* finding a random 1 < g < p-1
   g =2+ random(p-2)
%10 = 7557322358563246342
   */
   
   unsigned long long  p = 2147483647, g = 879788116;
   //p=18446744073709551557, g=13282407956253574714; //p =9223372036854775783 ,g = 7495541312104677200;
   unsigned long long  ra1[2], rb1[2], ra2, rb2, r, s;
  
   Alice(g, p, ra1);
   //printf("%llu \n", ra1[0]);
   //printf("%llu \n", ra1[1]);
   
   Bob(g, p, rb1);
   //printf("%llu \n", rb1[0]);
   //printf("%llu \n", rb1[1]);
   
   rb2 = Bob1(g, ra1[1], rb1[0], p);
   printf("%llu \n", rb2);
   ra2 = Alice1(g, rb1[1], ra1[0], p);
   printf("%llu \n", ra2);
   
   unsigned long long z = ra1[0]*rb1[0];
   
   //s = power(g, rb1[0], p);
   r = power(g, z, p);
   printf("verification:\n");
   printf("%llu \n", r);
  
   
   
    
   return 0;
   }			
