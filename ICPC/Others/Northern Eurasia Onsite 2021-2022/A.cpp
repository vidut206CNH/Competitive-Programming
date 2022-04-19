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

vector<pii> a(3);

signed main() {
	fast_cin();
	
	for(int i = 0; i < 3; ++i) {
		cin >> a[i].fi >> a[i].se;
	}
	
	sort(a.begin(), a.end());
	bool ok = true;
	for(int i = 0; i < 3; ++i) {
		ok &= (a[i].se == a[0].se);
	}
	
	if(ok) {
		cout << "1\n";
		cout << a[0].fi << " " << a[0].se << " " << a[2].fi << " " << a[2].se << "\n";
		exit(0);
	}
	
	int x = a[1].fi;
	vector<pii> res;
	int minn = inf, maxx = -inf;
	for(int i = 0; i < 3; ++i) {
		minn = min(a[i].se, minn);
		maxx = max(a[i].se, maxx);
		
		if(x != a[i].fi) {
			res.push_back({a[i].fi, a[i].se});
			res.push_back({x, a[i].se});
		}
	}
	
	
	res.push_back({x, minn});
	res.push_back({x, maxx});
	
	cout << sz(res)/2 << "\n";
	
	for(int i = 0; i < sz(res); i += 2) {
		for(int j = 0; j < 2; ++j) {
			cout << res[i + j].fi << " " << res[i + j].se << " \n"[j == 1];
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}