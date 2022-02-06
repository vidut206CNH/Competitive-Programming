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
const int inf = 2e18 + 7;

int t;
unordered_map<int, int> best[2];

int f(int a, int b) {
	best[0][a] = 0;
	best[1][b] = 0;
	while(true) {
		if(a == 1) break;
		int val = best[0][a];
		if(a&1) {
			++a;
			a >>= 1;
			best[0][a] = val + 2;
		} else {
			a >>= 1;
			best[0][a] = val + 1;
		}
	}
	
	while(true) {
		if(b == 1) break;
		int val = best[1][b];
		if(b&1) {
			--b;
			b >>= 1;
			best[1][b] = val + 2;
		} else {
			b >>= 1;
			best[1][b] = val + 1;
		}
	}
	
	int res = inf;
	
	for(auto x : best[0]) {
		for(auto y : best[1]) {
			if(x.fi > y.fi) continue;
/*			db(x.fi);
			db(y.fi);
			cerr << "\n";*/
			res = min(res, abs(x.fi - y.fi) + x.se + y.se);		
		}
	}
	
	return res;
}


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		best[0].clear();
		best[1].clear();
		int a,b;
		cin >> a >> b;
		int ans = f(a,b);
		cout << ans << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}