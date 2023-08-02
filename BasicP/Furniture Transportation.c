#include <stdio.h>

int main(){
	int n, l, m;
    scanf("%d %d %d", &n, &l, &m);
 
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
 
    int flag = 0;
    int combos = 0;
    for (int i = 0; i <= n - m; i++) {
        flag = 0;
        for (int j = i; j < i + m; j++) {
            if (a[j] > l) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            combos++;
        }
    }
 
    printf("%d\n", combos);
}
