#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
#define fr(i,n) for(i=1;i<=n;++i)
 
const ll N = 100000;
const ll M = 10001;
 
bitset<N> pre[M], cur, tp, mx;
 
int main()
{
 ll i,n,m,l,r,a,b,tp2,t,id;
 cin>>t;
 while(t--)
 {
 cin>>n>>m;
 cur = 0, pre[0] = 0, mx = 0, id = 0;
 fr(i,m)
 {
 cin>>l;
 if(l==1)
 {
 cin>>l>>r;
 l--, r--;
 tp=0, tp.flip();
 tp >>= (N-(r-l+1));
 tp <<= l;
 cur ^= tp;
 
tp = cur^mx;
 tp2 = tp._Find_first();
 if(tp2>=0 && tp2<N && mx[tp2]==0)
 mx = cur, id = i;
 
pre[i] = pre[i-1]^cur;
 }
 else if(l==2)
 {
 cin>>a>>b>>l>>r;
 l--, r--;
 pre[i] = pre[i-1]^cur;
 tp = pre[b]^pre[a-1];
 tp <<= (N-r-1);
 tp >>= (N-(r-l+1));
 tp2 = tp.count();
 if(tp2>0)
 cout<<tp2<<" "<<tp._Find_first()+l+1<<endl;
 else
 cout<<tp2<<" "<<0<<endl;
 }
 else
 {
 pre[i] = pre[i-1]^cur;
 cout<<id<<endl;
 }
 }
 } 
return 0;
}