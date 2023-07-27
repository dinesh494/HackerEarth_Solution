
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
typedef struct {
    int x;
    int y;
    //int p;  // bottom-left done flag
} point_t;
 
lint get_lint() { //Positive
	lint n =0;
	register int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	return n;
}
void put_lint (lint li, char lc) {//Negative
	if (0 == li) {
		pcx('0'); pcx(lc); return;
	} else if (li < 0) {
		pcx ('-'); li *= -1;
	}
	char s[24];
	auto idx =0;
	for (; li; idx++) {
		s[idx] = '0' + li % 10;
		li /= 10;
	}
	for (auto jdx=idx-1; jdx>=0; jdx--)
		pcx(s[jdx]);
	if(lc) pcx(lc);
	return;
}
 
int cmp(const void *p, const void *q) { //ASC Structure
    point_t *a = *(point_t**)p;
    point_t *b = *(point_t**)q;
    if (a->x != b->x)
        return (a->x > b->x);
    else
        return (a->y > b->y);
}
//modified version of binary-search
bool isPoint (point_t *pa[], lint r, int x, int y) {
    lint l = 0;
    lint m;
	while (l <= r) {
		m = (l + r)/2;
		if (pa[m]->x == x) {
		    if (pa[m]->y == y) return true;
		    lint mc = m;
		    do {
		        if (pa[mc]->y == y) return true;
    		    if (pa[mc]->y < y) {
    		        if (mc >= m) mc++;
    		        else return false;
    		    } else {
    		        if (mc <= y) mc--;
    		        else return false;
    		    }
		    } while (pa[mc]->x ==x);
		}
		if (pa[m]->x < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return false;
}
 
 
int main () {
	lint N = get_lint();
    point_t *pList = (point_t *) malloc (sizeof(point_t) * N);
    point_t *pA[N];
    for (auto pi=0; pi<N; pi++) {
        pList[pi].x = get_lint();
        pList[pi].y = get_lint();
        pA[pi] = pList + pi;
    }
    qsort (pA, N, sizeof(point_t*), cmp);
    
    lint maxLen =-1, maxLi =-1;
    for (auto pi=0; pi<N-1; pi++) {
        if (pA[pi]->x != pA[pi+1]->x)
            continue;
        lint lsLen = pA[pi+1]->y - pA[pi]->y;
        if (   isPoint(pA, N-1, pA[pi]->x +lsLen, pA[pi]->y) &&
                isPoint(pA, N-1, pA[pi+1]->x +lsLen, pA[pi+1]->y)) {
            if (lsLen > maxLen) {
                maxLen = lsLen; // left-side length;
                maxLi = pi;
            }        
        }
    }
    if (maxLen > 0) {
        put_lint(pA[maxLi]->x, ' ');
        put_lint(pA[maxLi]->y, 0);
    } else
        put_lint(-1, 0);
        
	return 0;
}