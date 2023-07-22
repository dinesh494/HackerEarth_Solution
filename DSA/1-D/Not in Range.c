//Not in Range
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
const int MX = 1000000;

int main() {
    ll n, res = 0;
    scanf("%lld", &n);

    int *arr = (int *)malloc((MX + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i <= MX; i++) {
        arr[i] = 0;
    }

    while (n--) {
        int l, r;
        scanf("%d %d", &l, &r);
        arr[l] += 1;
        arr[r + 1] += -1;
    }

    for (int i = 1; i <= MX; ++i) {
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i <= MX; ++i) {
        if (arr[i] == 0) {
            res += i;
        }
    }

    printf("%lld\n", res);
    free(arr);
    return 0;
}
