#include<stdio.h>

int reverse(int n)

{

int rev = 0, remainder;

while (n != 0) {

remainder = n % 10;

rev = rev * 10 + remainder;

n /= 10;

}

return rev;

}

int main()

{

int t;

scanf("%d",&t);

while(t--)

{

int a,b,sum=0;

scanf("%d %d",&a,&b);

sum=reverse(reverse(a)+reverse(b));

printf("%d\n",sum);

}

}