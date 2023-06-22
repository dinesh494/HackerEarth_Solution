#include <stdio.h>
#include <math.h>
int main()
{    
	unsigned long long int t;    
	scanf("%llu",&t);    
	while(t--)
	{        
		unsigned long long int k,n,ans,i,a;        
		scanf("%lld",&n);        
		i=1;        
		while(i<=sqrt(n))
		{            
		    i=i*2;       
	    }        
		if(n/i>=i/2)        
		a=n-n/i;        
		else        
		a=(n-(i/2))+1;        
		printf("%lld\n",a);    
	}
}