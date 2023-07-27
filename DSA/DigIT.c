#include <stdio.h>
 
#define DEBUG 0
 
long long A, B, K;
int X, Y;
 
int SimpleSolve() {
	int ans = 0, sd;
	long long V = (A / K) * K, W;
	if (V < A) V += K;
	for (; V <= B; V += K) {
		sd = 0;
		W = V;
		while (W > 0) {
			sd += (W % 10);
			W /= 10;
		}
		if (sd >= X && sd <= Y) ans++;
	}
	return ans;
}
 
#define MAXDIGITS 14
#define SMAX 118
#define KMAX 10001
 
long long cnt[MAXDIGITS][SMAX][KMAX];
int p10[MAXDIGITS];
 
void Precompute() {
	int i, s, k, nd, smax;
	cnt[0][0][0] = 1;
	for (i = 0; i <= 9; i++) cnt[1][i][i % K]++;
	p10[0] = 1 % K;
	for (i = 1; i < MAXDIGITS; i++) p10[i] = (p10[i - 1] * 10) % K;
	for (nd = 2; nd < MAXDIGITS; nd++) {
		smax = 9 * nd;
		for (s = 0; s <= smax; s++) {
			for (k = 0; k < KMAX; k++)
				for (i = 0; i <= 9 && i <= s; i++)
					cnt[nd][s][k] += cnt[nd - 1][s - i][(k - i * p10[nd - 1] + K * 10) % K];
			//if (nd == 2) fprintf(stderr, "   s=%d: %lld\n", s, cnt[nd][s][0]);
		}
	}
}
 
int d[MAXDIGITS], nd;
 
long long Solve(long long V) {
	if (DEBUG) fprintf(stderr, "[Solve] V=%lld\n", V);
	long long ans = 0;
	nd = 0;
	while (V > 0) {
		d[nd++] = V % 10;
		V /= 10;
	}
	int s, i, j, remk, sum;
 
	for (remk = sum = 0, i = nd - 1; i >= 0; i--) {
		for (j = 0; j < d[i]; j++) {
			int tmpremk = (remk + j * p10[i]) % K;
			int tmpsum = sum + j;
			s = Y - tmpsum;
			if (9 * i < s) s = 9 * i;
			for (; s >= 0 && s >= X - tmpsum; s--)
				ans += cnt[i][s][(K - tmpremk) % K];
			if (DEBUG) fprintf(stderr, "i=%d j=%d tmpremk=%d tmpsum=%d: ans=%lld\n", i, j, tmpremk, tmpsum, ans);
		}
		remk = (remk + d[i] * p10[i]) % K;
		sum += d[i];
	}
	if (remk == 0 && X <= sum && sum <= Y) ans++;
	if (DEBUG) fprintf(stderr, "final ans=%lld\n", ans);
	return ans;
}
 
int main() {
//	freopen("y.txt", "r", stdin);
	scanf("%lld %lld %d %d %lld", &A, &B, &X, &Y, &K);
	if (K >= KMAX) {
		printf("%d\n", SimpleSolve());
	} else {
		Precompute();
		printf("%lld\n", Solve(B) - Solve(A - 1));
		if (DEBUG) fprintf(stderr, "debug: %d\n", SimpleSolve());
	}
	return 0;
}