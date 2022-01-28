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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		if(k == n - 1 && n == 4) {
			cout << -1 << "\n";
			continue;
		}
		vector<pii > res;
		if(k != n-1) {
			if(k == 0) {
				res.push_back({0, n - 1});
			}
			for(int i=1;i<n/2;++i) {
				if(i == k) {
					res.push_back({n-1, i});
					res.push_back({n - 1 - i, 0});
				} else if(n - 1 - i == k) {
					res.push_back({n-1, n - i - 1});
					res.push_back({i, 0});
				}
				else res.push_back({i, n - i - 1});
			}
		}
		
		if(k == n - 1) {
			res.push_back({n/2, n/2 + 1});
			res.push_back({n/2 - 1, n - 1});
			for(int i=1;i< n/2 - 2; ++i) {
				res.push_back({i, n - i - 1});
			}
			res.push_back({0, n/2 - 2});
		}
		for(auto x : res) cout << x.fi << " " << x.se << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}