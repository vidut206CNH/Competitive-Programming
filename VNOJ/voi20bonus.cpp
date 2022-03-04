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
const int MAXN1 = 310;
const int MAXN2 = 1e6+5;
const int inf = 1e9;

int n,k;
int a[MAXN1];
int dp[MAXN1][MAXN1][MAXN1/2 + 5];

int calc(int l, int r, int rem) {
/*	db(l);
	db(r);
	db(rem);
	cerr << '\n';*/
	if(rem == 0) return 0;
	if(l == r) return -inf;
	if(dp[l][r][rem] != -1) return dp[l][r][rem];
	if(l + 1 == r) {
		if(rem != 1) return -inf;
		return dp[l][r][rem] = abs(a[r] - a[l]);
	}
	
	return dp[l][r][rem] = max({calc(l + 2, r, rem - 1) + abs(a[l] - a[l + 1]),
								 calc(l, r - 2, rem - 1) + abs(a[r] - a[r - 1]),
								 calc(l + 1, r - 1, rem - 1) + abs(a[r] - a[l]),
								 calc(l + 1, r, rem), calc(l, r - 1, rem)});
	
	
}


signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << calc(1, n, k);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}