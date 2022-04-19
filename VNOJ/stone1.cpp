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
const int MAXN1 = 405;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
vector<int> child[MAXN1];
int dp[MAXN1];

void dfs(int u) {
	if(child[u].empty()) dp[u] = 1;
	vector<int> f;
	
	for(auto v : child[u]) {
		dfs(v);
		f.push_back(dp[v]);
	}
	
	sort(f.begin(), f.end(), greater<int>());
	
	for(int i = 0; i < sz(f); ++i) {
		dp[u] = max(dp[u], f[i] + i);
	}
/*	db(u);
	db(dp[u]);
	cerr << "\n";*/
}


signed main() {
	fast_cin();
	
	
	cin >> n;
	int u;
	while(cin >> u) {
		int t;
		cin >> t;
		for(int i = 1; i <= t; ++i) {
			int v;
			cin >> v;
			child[u].push_back(v);
		}
	}
	
	dfs(1);
	
	cout << dp[1];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}