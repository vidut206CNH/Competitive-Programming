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

int n;
vector<int> child[MAXN1];
int dp[MAXN1];

void dfs(int u) {
	vector<int> p;
	for(auto v : child[u]) {
		dfs(v);
		p.push_back(dp[v]);
	}
	
	sort(p.begin(), p.end(), greater<int>());
	
	for(int i = 0; i < sz(p); ++i) {
		dp[u] = max(dp[u], p[i] + i + 1);
	}
	
/*	db(dp[u]);
	db(u);
	cerr << "\n";*/
	
}
signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		child[x].push_back(i);
	}
	
	dfs(1);
	
	cout << dp[1];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}