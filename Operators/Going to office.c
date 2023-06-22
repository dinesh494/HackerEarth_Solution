#include<stdio.h> 
int main()
{
long long int d,oc,of,od,cs,cb,cm,cd,a=0,b=0;
scanf("%lld",&d);
scanf("%lld %lld %lld",&oc,&of,&od);
scanf("%lld %lld %lld %lld",&cs,&cb,&cm,&cd);
a=oc+(d-of)*od;
b=cb+(d/cs)*cm+d*cd;
if(a<=b)
{
 printf("Online Taxi\n");
 }
else
{
printf("Classic Taxi\n");
} 
}