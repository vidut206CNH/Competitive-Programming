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
const int MAXN1 = 5005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
vector<int> adj[MAXN1];
bool poss[MAXN1];
vector<int> f(MAXN1, 1);


void dfs(int cur = 1, int par = 0) {
	
	
	vector<bool> ok(n+1,false);
	
	ok[0] = 1;
	
	for(auto x : adj[cur]) {
		if(x == par) continue;
		
		dfs(x, cur);
		
		f[cur] += f[x];
		
		int g = f[x];
		
		for(int val = n - 2 - g; val >= 0; --val) {
			if(ok[val]) ok[val + g] = 1;
		}
	}
	
	for(int i=1;i<=n - 2;++i) {
		poss[i] |= (ok[i]);
	}
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<n;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs();
	
	for(int i=1;i<=n-2;++i) {
		if(poss[i]) poss[n - 1 - i] = true;
	}
	int cnt = 0;
	vector<pii > res;
	for(int i=1;i<=n-2;++i) {
		if(poss[i]) {
			cnt++;
			res.push_back({i, n - 1 - i});
		}
	}
	
	cout << cnt << "\n";
	for(auto x : res) cout << x.fi << " " << x.se << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}