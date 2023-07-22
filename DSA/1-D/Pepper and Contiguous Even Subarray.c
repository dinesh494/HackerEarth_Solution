//Pepper and Contiguous Even Subarray <Debugging>
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, res = 0, cnt = 0;
        scanf("%d", &n);

        while (n--) {
            int x;
            scanf("%d", &x);

            if (x & 1) {
                res = (res > cnt) ? res : cnt;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        res = (res > cnt) ? res : cnt;
        printf("%d\n", (res ? res : -1));
    }
    return 0;
}