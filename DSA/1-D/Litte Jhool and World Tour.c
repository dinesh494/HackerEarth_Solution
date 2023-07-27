#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              	                  // Reading input from STDIN
	while(num)
	{
		int n,m,f=0;
		scanf("%d%d",&n,&m);
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==y)
			{
				f=1;
				break;
			}
			else if(x>n && x>y)
			{
				if((x-y)>n)
				{
					f=1;
				}
			}
		}
		if(f==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		num--;
	}
}