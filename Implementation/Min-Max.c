#include <stdio.h>

int main()
{
    int i, N, a[1000],min=0,max=0,count=0,c=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        if(count==0){
            min=a[i];
            max=a[i];
        }
        else{
            if(a[i]<min){
                min=a[i];
            }else if(a[i]>max){
                max=a[i];
            }
        }
        count++;
    }
 count=0;
 for(i=min;i<=max;i++){
 count++;
 } 
 i=0;
     for(;i<N&&min<=max;){
 if(min==a[i]){
 c++;
 i=0;
 min++;
 }
 else{
 i++;
 }
 }       
 //printf("%d %d",c,count);           
 if(c==count){
 printf("YES");
 }
 else{
 printf("NO");
 } 
    
    return 0;
}