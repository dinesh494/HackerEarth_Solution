#include <stdio.h>


 

int main(){

    int t,n;

    scanf("%d", &t);           

    for(int i=0;i<=t-1;i++){

scanf("%d", &n);


 

int k=n;


 

if(k>=3&&k%4==0)

{printf("1");

    printf(" %d\n",k);}

else if(k>3&&k%4==1)

{printf("1");

printf(" %d\n",1);}

else if(k>3&&k%4==2)

{printf("2");

    printf(" %d %d\n",k,1);}

else if(k>=3&&k%4==3)

printf("0\n");

else if(k%4==0)

{printf("1");

    printf(" %d\n",k);}

else if(k==1)

{printf("1");

    printf(" %d\n",k);

}

else if(k==2){

printf("2");

printf(" %d %d\n",k,k-1);   

}

}

    

    return 0;

}