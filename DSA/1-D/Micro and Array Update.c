
#include <stdio.h>

const int inf = 1e9;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, mn = inf, n, k;
        scanf("%d%d", &n, &k);
        while (n--) {
            scanf("%d", &x);
            mn = (mn < x) ? mn : x;
        }
        printf("%d\n", ((mn < k) ? (k - mn) : 0));
    }
    return 0;
}