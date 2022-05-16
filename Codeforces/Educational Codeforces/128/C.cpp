/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int n;
int a[MAXN1];
int f[MAXN1];
int best[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		vector<pii> p;
		set<int> st;
		string s;
		cin >> s;
		n = s.size();
		s = '0' + s;
		for(int i = 1; i <= n; ++i) {
			a[i] = s[i] - '0';
			f[i] = f[i - 1] + a[i];
			p.push_back({i, f[i]});
		}
		
		sort(p.begin(), p.end());
		st.insert({0, 0});
		
		for(auto x : p) {
			int pos = x.fi;
			int val = x.fi - x.se;
			
			auto it  = st.lower_bound({val, 0LL});
			if(it != st.end()) {
				best[pos] = max(pos - it->se, it->fi - it->se);
			}
			
			if(it != st.begin()) {
				--it;
				best[pos] = max(pos - it->se, it->fi - it->se);
			}
			
			db(best[pos]);
			cerr << "\n";
			
			st.insert(pos);
		}
		
		cerr << "\n";
		int res = inf;
		int sum = 0;
		for(int i = n + 1; i >= 1; --i) {
			sum += a[i];
			res = min(res, max(sum, best[i - 1]));	
		}
		
		cout << res << "\n";
		
		
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}