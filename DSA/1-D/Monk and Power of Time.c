
#include <stdio.h>

#define MX 100

int arr[MX];

int main() {
    int n, nn, x, idx = 0, cidx = 0, zeros = 0, res = 0;
    scanf("%d", &n);
    nn = n;

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    while (nn--) {
        scanf("%d", &x);
        for (;;) {
            if (!arr[idx % n])
                zeros++;
            if (arr[idx % n] == x) {
                res += (((idx - cidx) % n) + 1) - zeros;
                zeros = arr[idx % n] = 0;
                cidx = idx;
                break;
            }
            idx++;
        }
    }

    printf("%d", res);
    return 0;
}