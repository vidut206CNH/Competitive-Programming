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

int n,m;
pii a[MAXN1];
int dp[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> m >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	
	int hi = a[1].se;
	int res = 1;
	for(int i = 1; i <= n; ++i) {
		if(a[i].fi <= hi) {
			hi = min(a[i].se, hi);
			continue;
		}
		res++;
		hi = a[i].se;
	}	
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}