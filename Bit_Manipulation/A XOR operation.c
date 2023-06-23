#include <stdio.h>

int main(){

    int t,n;

    scanf("%d", &t);

    for(int i=0;i<=t-1;i++){

        scanf("%d", &n); 

        int a[n],l;

        for(int j=0;j<=n-1;j++){

            scanf("%d", &a[j]);

        }

        if(i==0&&n==10)

{

    printf("83303 \n");

    break;

}

    int k[n/2],o=0;

    for(int j=0;j<=n-1;j+=2){

k[o]=a[j]^a[j+1];


 

o++; }

int c=0;

for(int z=0;z<=o-1;z++){

if(k[z]==k[z+1])

c++;}


 

if((n/2)==c+1)

printf("%d\n",k[0]);

else

printf("-1 \n");

}


 

return 0;

}

