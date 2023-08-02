#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
 
typedef int32_t ichar; 
typedef int_fast64_t fint; 
 
static inline fint getfi () {
    ichar c = gcx();
    while (!isdigit (c)) c = gcx();
    fint n = 0;
    while (isdigit (c)) {
        n = n * 10 + c - '0';
        c = gcx();
    }
    return n;
}
static inline void putfi (fint n, char lc) {
    if (0 == n) {
        pcx ('0');
        if (lc) pcx (lc);
        return;
    }
    char s[24];
    fint rdi = 0;
    while (n) {
        s[rdi++] = '0' + n % 10;
        n /= 10;
    }
    while (rdi) pcx (s[--rdi]);
    if (lc) pcx (lc);
}
 
int main () {
    int FA[1000002] = {0};
    fint N = getfi() + 1;
    fint Q = N;
    fint nMax = -1;
    while (--Q) {
        fint X = getfi();
        ++FA[(int)X];
        if (X > nMax) nMax = X;
    }
    fint *FS = calloc (sizeof(fint), N+1);
    for (fint ni=1; ni <= nMax; ++ni) {
        if (FA[ni]) 
            FS[FA[ni]] += ni * FA[ni];
    }
    for (fint ni=1; ni <= N; ++ni)
        FS[ni] += FS[ni-1];
    Q = getfi() +1;
    while (--Q) {
        fint L = getfi() -1;
        //fint R = getfi();
        putfi(FS[getfi()] - FS[L], '\n');
    }
 
    return 0;
}