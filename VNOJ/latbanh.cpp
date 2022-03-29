/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int MAXN1 = 5e5+5;
const int MAXN2 = 105;
const int inf = 1e9 + 7;

int n,k;
pii a[MAXN2];

int dp[2][MAXN1][MAXN2];

int calc(bool ok, int val, int pos) {
	if(val > n) return inf;
	if(pos  == k + 1) {
		if(ok) val += (2*n - a[pos - 1].se);
		if(val != n) return inf;
		return 0;
	}
	
	if(dp[ok][val][pos] != -1) return dp[ok][val][pos];
	int res = inf;
	
	for(int l = a[pos].fi; l <= a[pos].se; ++l) {
		
		if(ok && val + l - a[pos - 1].se <= n) {
			int val1 = val + l - a[pos - 1].se;
			res = min(res, calc(!ok, val1, pos + 1) + 1);
			
			for(int r = l + 1; r <= a[pos].se; ++r) {
				res = min(res, calc(ok, val1 + a[pos].se - r, pos + 1) + 2);
			}
		}
		
		else if(!ok) {
			int val1 = val + a[pos].se - l;
			res = min(res, calc(!ok, val1, pos + 1) + 1);
			
			for(int r = l + 1; r <= a[pos].se; ++r) {
				res = min(res, calc(ok, val1 - (a[pos].se - r), pos + 1) + 2);
			}
		}
	}
	
	if(ok) {
		res =min(res, calc(ok, val + a[pos].se - a[pos - 1].se, pos + 1));
	}
	else {
		res = min(res, calc(ok, val, pos + 1));
	}
	
	return dp[ok][val][pos] = res;
	
}

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= k; ++i) {
		cin >> a[i].fi >> a[i].se;
	}
	memset(dp, -1, sizeof dp);
	
	int res = calc(1, 0, 1);
	cout << (res == inf ? -1 : res);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}