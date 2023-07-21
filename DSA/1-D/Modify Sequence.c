
#include <stdio.h>
#include <stdbool.h>

#define MX 10000

int arr[MX + 1], n;

bool check() {
    for (int i = 1; i < n; ++i) {
        arr[i] -= arr[i - 1];
        arr[i - 1] = 0;
        if (arr[i] < 0)
            return false;
    }
    return ((arr[--n] == 0) ? true : false);
}

int main() {
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    printf("%s\n", (check() ? "YES" : "NO"));

    return 0;
}