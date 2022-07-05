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

const int MOD = 1e10 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int n;
pii a[MAXN1];
vector<pii> X[2],Y[2];

signed main() {
	fast_cin();
	
	cin >> n;	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;
		X[0].push_back({a[i].fi - a[i].se, -a[i].fi});
		X[1].push_back({a[i].fi + a[i].se, -a[i].fi});
		Y[0].push_back({a[i].se - a[i].fi, -a[i].se});
		Y[1].push_back({a[i].se + a[i].fi, -a[i].se});
	}
	
	sort(X[0].begin(), X[0].end(), greater<>());
	sort(Y[0].begin(), Y[0].end(), greater<>());
	sort(X[1].begin(), X[1].end(), greater<>());
	sort(Y[1].begin(), Y[1].end(), greater<>());
	
	int minn0 = MOD, minn1 = MOD;
	int res = 0;
	
	for(int i = 0; i < n; ++i) {
		res = max(res, -X[0][i].se - minn0);
		minn0 = min(minn0, -X[0][i].se);
		
		res = max(res, -X[1][i].se - minn1);
		minn1 = min(minn1, -X[1][i].se);
	}
	
	minn0 = MOD, minn1 = MOD;
	
	for(int i = 0; i < n; ++i) {
		res = max(res, -Y[0][i].se - minn0);
		minn0 = min(minn0, -Y[0][i].se);
		
		
		res = max(res, -Y[1][i].se - minn1);
		minn1 = min(minn1, -Y[1][i].se);
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}