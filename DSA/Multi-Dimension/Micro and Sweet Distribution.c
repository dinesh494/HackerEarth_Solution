#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
 
#define MA 1000000000000000000 // 1e18
#define M  1000000007
#define MM 2000000000
#define N  100001
#define K  101
 
typedef long long ll;
typedef long double ld;
 
ll n,m;
ll a[N];
ll s[N];
 
int main() {
  ll t;
  ll i,j,k,q,c,d,l,r,x;
  ll sx,sy, dx,dy;
  t=1;
  scanf("%lld ", &t);
 
  while(t--) {
    scanf("%lld %lld", &n, &m);
    scanf("%lld %lld", &sy, &sx);
    scanf("%lld %lld", &dy, &dx);
 
    if (sy==1) {
      if (sx==1) {
        if ((dy-sy)%2==0) { // right or down or over
          if (dx<m) puts("Right");
          else if (dy<n) puts("Back");
          else puts("Over");
        } else { // left or down or over
          if (dx>1) puts("Left");
          else if (dy<n) puts("Back");
          else puts("Over");
        }
      } else {
        if ((dy-sy)%2==0) { // left or down or over
          if (dx>1) puts("Left");
          else if (dy<n) puts("Back");
          else puts("Over");
        } else { // right or down or over
          if (dx<m) puts("Right");
          else if (dy<n) puts("Back");
          else puts("Over");
        }
      }
    } else {
      if (sx==1) {
        if ((dy-sy)%2==0) { // right or up or over
          if (dx<m) puts("Right");
          else if (dy>1) puts("Front");
          else puts("Over");
        } else { // left or up or over
          if (dx>1) puts("Left");
          else if (dy>1) puts("Front");
          else puts("Over");
        }
      } else {
        if ((dy-sy)%2==0) { // left or up or over
          if (dx>1) puts("Left");
          else if (dy>1) puts("Front");
          else puts("Over");
        } else { // right or up or over
          if (dx<m) puts("Right");
          else if (dy>1) puts("Front");
          else puts("Over");
        }
      }
    }
  }
}