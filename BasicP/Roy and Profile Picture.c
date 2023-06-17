#include <stdio.h>
int main(){
    int l,n;
    scanf("%d\n%d",&l,&n);
    int arr[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        if( (arr[i][0] == arr[i][1]) && (arr[i][0] >= l)){
            printf("ACCEPTED\n");
        }
        else if( (arr[i][0] != arr[i][1]) && (arr[i][0] >= l && arr[i][1] >=l)){
            printf("CROP IT\n");
        }
        else if(arr[i][0]<l || arr[i][1]<l){
            printf("UPLOAD ANOTHER\n");
        }
             }
}