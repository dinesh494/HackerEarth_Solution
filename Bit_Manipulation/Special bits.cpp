  #include<bits/stdc++.h>
        typedef long long ll;
        typedef double ld;
        #define vll vector<ll>
        #define pll pair<ll ,ll >
        #define vllp vector< pll >
        #define mp make_pair
        #define pb push_back
        #define MOD 1000000007
        #define endl "\n"
        #define all(v) v.begin(),v.end()
        #define rall(v) v.rbegin(),v.rend()
        #define F first
        #define S second
        #define MAX 1000000007
        using namespace std;

        bool is_true(string s, ll r)
        {
            ll l = 0;
            ll po = 1;
            for (int i = 61; i >= 0; i--)
            {
                if (s[i] == '1')
                    l += po;
                po *= 2;
            }
            if (l <= r)
                return true;
            return false;
        }
        ll to_long(string s)
        {
            ll l = 0;
            ll po = 1;
            for (int i = 61; i >= 0; i--)
            {
                if (s[i] == '1')
                    l += po;
                po *= 2;
            }
            return l;
        }
        ll more_bit(ll l, ll r, ll k, ll l_bits)
        {
            string sl = bitset<62>(l).to_string();
            for (int i = 61; i >= 0; --i)
            {
                if (sl[i] == '0')
                {
                    sl[i] = '1';
                    l_bits++;
                }
                if (is_true(sl, r) && l_bits == k)
                    return to_long(sl);
            }
            return -1;
        }
        ll less_bit(ll l, ll r, ll k, ll l_bits)
        {
            ll co = 0;
            string sl = bitset<62>(l).to_string();
            for (int i = 61; i >= 0; i--)
            {
                if (sl[i] == '1')
                    co++;
                if (sl[i] == '0')
                {
                    string s = sl;
                    s[i] = '1';
                    for (int j = i + 1; j < 62; ++j)
                    {
                        s[j] = '0';
                    }
                    if (is_true(s, r) && l_bits - co + 1 == k)
                        return to_long(s);
                    if (is_true(s, r) && l_bits - co + 1 < k)
                        return more_bit(to_long(s), r, k, l_bits - co + 1);
                }
            }
            return -1;
        }
        ll fun(ll l, ll r, ll k)
        {
            string sl = bitset<62>(l).to_string();
            string sr = bitset<62>(r).to_string();
            int set_bit = 0;
            for (int i = 0; i < 62; ++i)
            {
                if (sl[i] != sr[i])
                    break;
                if (sl[i] == '1')
                    set_bit++;
            }
            if (set_bit > k)
                return -1;
            int l_set_bit = 0;
            for (int i = 0; i < 62; ++i)
            {
                if (sl[i] == '1')
                    l_set_bit++;
            }
            if (l_set_bit < k)
            {
                return more_bit(l, r, k, l_set_bit);
            }
            if (l_set_bit == k)
                return l;
            return less_bit(l, r, k, l_set_bit);
        }
        void solve() {
            ll n;
            ll l, r, k;
            cin >> l >> r >> k;
            cout << fun(l, r, k) << endl;
        }

        int main() {
            ios::sync_with_stdio(0); cin.tie(0);
            int t = 1;
            cin >> t;
            while (t--) {
                solve();
            }
            return 0;
        }