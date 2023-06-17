#include <stdio.h>

int main() {
    int n;
    long long product, value;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("invalid input\n");
        return 1;
    }
    product = 1;
    while (n--) {
        if (scanf("%lld", &value) != 1) {
            printf("invalid input\n");
            return 1;
        }
        product = product * value % 1000000007;
    }
    printf("%lld\n", product);
    return 0;
}