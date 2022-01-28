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

pii p[3];

signed main() {
	fast_cin();
	
	for(int i=0;i<3;++i) {
		cin >> p[i].fi >> p[i].se;
	}
	
	sort(p, p + 3);
	set<pii > res;
	int l = min({p[0].se, p[1].se, p[2].se});
	int r = max({p[0].se, p[1].se, p[2].se});
	int m = p[1].fi;
	
	for(int i=l;i <= r;++i) {
		res.insert({m,i});
	}
	
	for(int i=p[0].fi; i < m; ++i) {
		res.insert({i, p[0].se});
	}
	for(int i=p[2].fi; i > m;--i) {
		res.insert({i, p[2].se});
	}
	
	cout << sz(res) << "\n";
	for(auto x : res) cout << x.fi << " " << x.se << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}