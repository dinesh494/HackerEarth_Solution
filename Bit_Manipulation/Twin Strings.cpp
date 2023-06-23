#include<bits/stdc++.h> 
using namespace std; 
#define int long long 
#define endl "\n" 
int getMask(vector<int>&a) 
{   
	  int n = a.size();     
	  int ans = 0;     
	  for (int i = 0; i < n; i++) 
	  {         
		if (a[i] & 1) 
		{             
			ans |= 1;         
			}         
			ans <<= 1;     
			}     
			ans >>= 1;     
			return ans; 
			} 
			void solve() 
			{     
				int n;     
				cin >> n;     
				string s;     
				cin >> s;     
				vector<int>cnt(26, 0);    
				unordered_map<int, int>m;    
				m[0]++;     
				int ans = 0;     
				for (int i = 0; i < n; i++) 
				{         cnt[s[i] - 'a']++;         
				int x = getMask(cnt);         
				ans += m[x];         
				m[x]++;     
				}     
				cout << ans << endl; 
				} 
				signed main() 
					{     
						ios_base::sync_with_stdio(0);     
						cin.tie(0); cout.tie(0);     
						int t = 1;     
						cin >> t;     
						while (t--)
						 {         
							solve();
							}     
							return 0;
			}