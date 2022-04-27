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
vector<int> adj[MAXN1];
map<pii, int> mp;
vector<pii> p;

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		p.push_back({u,v});
		
	}
	
	bool ok = true;
	for(int i = 1; i <= n; ++i) {
		ok &= (sz(adj[i]) <= 2);
	}
	
	if(ok) {
		for(int i = 0; i <= n - 2; ++i) cout << i << "\n";
		return 0;
	}
	
	
	for(int u = 1; u <= n; ++u) {
		if(sz(adj[u]) >= 3) {
			for(int i = 0; i < 3; ++i) {
				int v = *adj[u].begin();
				mp[{u, v}] = i + 1;
				mp[{v, u}] = i + 1;
				adj[u].erase(adj[u].begin());
				
			}
			break;
		}
	}
	int cnt = 3;
	
	for(int u = 1; u <= n; ++u) {
		for(auto v : adj[u]) {
			if(mp[{u,v}]) continue;
			mp[{u, v}] = ++cnt;
			mp[{v, u}] = cnt;
		}
	}
	
	for(auto x : p) {
		cout << mp[x] - 1 << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}