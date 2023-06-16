#include <stdio.h>

int main()
{
    int m,c,count1=1,a[108]={0},b[108]={0},i,l,j,T,N,k;
    char c1[108],c2[108]; for(j=0;j<108;) {
            if(count1<=6){
                a[j]=j+1;
                if(count1==1 || count1==6)
                {
                    c1[j]='W';
                }
                else if(count1==2 || count1==5)
                {
                    c1[j]='M';
                }
                else if(count1==3 || count1==4)
                {
                    c1[j]='A';
                }
                count1++;
                j++;}
            else{
                count1=1;
                j=j+6;
            }}
        count1=1;k=108;c=5;j=101;m=j;
        for(j=101;j>=0;){ if(count1<=6){
                l=m-c;
                b[l]=k;
                if(count1==1 || count1==6){
                    c2[l]='W';
                }
                else if(count1==2 || count1==5){
                    c2[l]='M';
                }
                else if(count1==3 || count1==4){
                    c2[l]='A';
                }
                count1++;
                j--;
                k--;
                 l--;
                c--;
            }

            else{
                count1=1;
                j=j-6;
                k-=6;
                c=5;
                m=j;
            } }
        scanf("%d",&T);
        for(i=0;i<T;i++){
            scanf("%d",&N);
            for(j=0;j<108;j++){
                if(a[j]==N){
                    printf("\n%d %cS",b[j],c2[j]);
                }
                else if(b[j]==N){
                    printf("\n%d %cS",a[j],c1[j]);
                } }}


    return 0;
}
