#include <stdio.h> 
int main(){     
	int Testcases;     
	scanf("%d",&Testcases);     
	for(int i=1;i<=Testcases;i++){         
		int n;         scanf("%d",&n);         
		int arr[n];         
		for(int j=0;j<n;j++){             
			scanf("%d",&arr[j]);         
			}         
			int m=arr[0];         
			for(int j=0;j<n;j++){             
				if(arr[j]<m){                 
					m=arr[j];             
					}         
					}         
					printf("%d \n",m);     
					}     
					return 0; 
					}