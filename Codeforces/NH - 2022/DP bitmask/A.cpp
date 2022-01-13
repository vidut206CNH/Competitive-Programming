/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 1LL << 20;
const int MAXN2 = 1e6+5;
const int inf = 1e9;

int n,m;
int a[25][25];
int dp[MAXN1][20];

int inv(int x, int bit) {
	return (x & (~(1LL << bit)));
}

int calc(int state, int ed) {
	if(dp[state][ed] != 0) return dp[state][ed];
	if((int)__builtin_popcount(state) == 1) {
		if(a[0][ed] == 0) return dp[state][ed] = inf;
		return dp[state][ed] = a[0][ed];
	}
/*	db(state);
	db(ed);
	cerr << "\n";*/
	int ans = inf,nex = inv(state, ed);
	
	for(int i=0;(1LL << i) <= state;++i) {
		if((state >> i & 1) && i != ed && a[i][ed] != 0) {
			ans = min(ans, calc(nex, i) + a[i][ed]);
		}
	}
	dp[state][ed] = ans;
	return dp[state][ed];
}

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i=1;i<=m;++i) {
		int u,v,c;
		cin >> u >> v >> c;
		--u;
		--v;
		a[u][v] = c;
	}
	
	cout << calc((1LL << n) - 1, 0);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}