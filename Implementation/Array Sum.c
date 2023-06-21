#include <stdio.h> 
int main(){     
	int num;     
	scanf("%d", &num);     
	long long int a[num],sum=0;     
	for(int i=0;i<num;i++)     {     
		scanf("%lld",&a[i]);     
		sum+=a[i];}     
		printf("%lld",sum);
		}