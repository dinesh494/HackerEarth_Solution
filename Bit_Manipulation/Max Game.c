#include<stdio.h>
#include<stdbool.h> 
#include<malloc.h>   
int solve (int N) {     
    int pos,p,n=0;     
    for(pos=0,p=n;pos<=31;pos++)     {         
        n=1<<pos|n;         
        if(n>N)         {         
            n=(1<<pos-1)|p;         
            return n;         
            }         
            n=p=0;     
            }     
            }
int main() 
{     
    int T;     
    scanf("%d", &T);     
    for(int t_i = 0; t_i < T; t_i++)     {         
        int N;         
        scanf("%d", &N);
         int out_ = solve(N);         
         printf("%d", out_);         
         printf("\n");     
         }
         }