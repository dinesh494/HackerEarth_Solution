#include <bits/stdc++.h>

 

using namespace std;

 

bool chk[252];

int dp[10002];

 

int main()

{

int t,n,m,l,r;

string s,p;

 

int ans;

 

cin >> t;

while ( t-- ) {

 memset(chk, false, sizeof(chk));

 cin >> n >> m >> l >> r;

 cin >> s >> p;

 for ( int i = 0; i < p.size(); i++ ) {

  assert(p[i]>=0&&p[i]<=251);

  chk[p[i]] = true;

 }

 dp[0] = 0;

 ans = 0;

 for ( int i = 1; i <= n; i++ ) dp[i] = dp[i-1] + chk[s[i-1]];

 for ( int i = 1; i <= n; i++ ) {

  int lf,rt,md,fs=-1,sc=n+1;

  lf = i, rt = n, md = -1;

  while ( lf <= rt ) {

   md = (lf+rt)/2;

   int val = dp[md] - dp[i-1];

   if ( val >= l ) {

    fs = md;

    rt = md-1;

   }

   else if ( val < l ) lf = md+1;

  }

  if ( fs == -1 ) continue;

  lf = i,rt = n, md = -1;

  while ( lf <= rt ) {

   md = (lf+rt)/2;

   int val = dp[md] - dp[i-1];

   if ( val > r ) {

    sc = md;

    rt = md-1;

   }

   else lf = md+1;

  }

  ans += sc-fs;

 }

 cout << ans << endl;

}

return 0;

}