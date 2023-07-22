//Speed
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, mx = 1000000000, res = 0;
        scanf("%d", &n);
        
        while (n--) {
            int x;
            scanf("%d", &x);
            
            if (x <= mx) {
                res++;
                mx = x;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}