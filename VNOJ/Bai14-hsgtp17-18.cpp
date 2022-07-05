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

const long long MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n;
vector<int> child[MAXN2];
long long dp[MAXN2];

void dfs(int u) {
	dp[u] = 1;
	for(int v : child[u]) {
		dfs(v);
		
		dp[u] = dp[u]*dp[v]%MOD; 
	}
	
	dp[u] = (dp[u] + 1)%MOD;
}

int main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		child[x].push_back(i);
	}
	
	dfs(n);
	
	cout << (dp[n] - 1 + MOD)%MOD;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}