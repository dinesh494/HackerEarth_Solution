#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
 
typedef int32_t ichar; 
typedef int_fast64_t fint; 
 
static inline fint getnfi() {
	fint n =0, neg =0;
	ichar c = gcx();
	if ('-' == c) { neg =1; c = gcx(); }
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	if(neg) n = ~n +1;
	return n;
}
static inline void putnfi (fint n, char lc) {
	if (0 == n) {
        pcx('0'); if(lc) pcx(lc); return;
	} else if (n < 0) {
        pcx ('-'); n = ~n +1;
	}
	char s[24]; fint rdi =-1;
	while (n) {
		s[++rdi] = '0' + n % 10;
		n /= 10;
	}
	while (rdi>=0) pcx(s[rdi--]);
	if(lc) pcx(lc);
}
int cmp(const void *p, const void *q) { //DSC Order
	return (*(fint*)p < *(fint*)q);
}
 
int main () {
    fint* NA = malloc (500002*sizeof(fint));
    fint* SA = calloc (500002,sizeof(fint));
 
    fint T = getnfi() + 1;
    while (--T) {
        fint N = getnfi();
        fint K = getnfi();
        for (fint ni=0; ni<N; ++ni) {
            NA[ni] = getnfi();
            if (NA[ni] < 1) {--N, --ni;}
        }
        qsort (NA, N, sizeof(fint), cmp);
        //for (fint ni=0; ni < N; ) printf ("%ld ", NA[ni++]); pcx('\n');
        fint Si = 0;
        SA[Si] = NA[0];
        for (fint ni=1; ni<N; ++ni) {
            if (NA[ni-1] == NA[ni])
                SA[Si] += NA[ni];
            else
                SA[++Si] = NA[ni];
        } ++Si;
        qsort (SA, Si, sizeof(fint), cmp);
        //for (fint ni=0; ni < Si; ) printf ("%ld ", SA[ni++]); pcx('\n');
        fint ans = 0;
        K = (Si < K)? Si : K;
        for (fint si=0; si<K; )
            if (SA[si] < 0) break;
            else ans += SA[si++];
        putnfi(ans, '\n');
        memset (SA, 0, Si*sizeof(fint));
    }
    return 0;
}