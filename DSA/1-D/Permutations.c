#include <stdio.h>
 
int main(){
    int n, q;
    scanf("%d %d", &n,&q);
    int a[100001];
    int lft[100001];
    int rht[100001];
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int ml = 0;
    int mr = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] > ml){
            ml = a[i];
        }
        lft[i] = ml;
        if (a[n + 1 - i] > mr){
            mr = a[n + 1 - i];
        }
        rht[n + 1 - i] = mr;
    }
 
    for (int i = 0; i < q; i++){
        int l, r;
        scanf("%d %d", &l,&r);
        int max = 0;
        if (lft[l - 1] > rht[r + 1]){
            printf("%d\n", lft[l - 1]);
        }
        else{
            printf("%d\n", rht[r + 1]);
        }
    }
}