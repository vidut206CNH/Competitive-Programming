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
int f1[MAXN1];
int f2[MAXN1];
vector<int> adj[MAXN1];
int p[MAXN1];
bool ok = true;

void dfs1(int u, int par) {
	if(sz(adj[u]) == 1) f1[u] = p[u];
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		dfs1(v, u);
		
		f1[u] += f1[v];
	}
}

void dfs2(int u, int par) {
	if(sz(adj[u]) == 1) {
		f2[u] = p[u];
	}
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		f2[v] += f2[u];
		dfs2(v, u);
	}
}

void dfs3(int u, int par) {
	
	db(u);
	if(sz(adj[u]) == 1) {
		ok &= (p[u] == (f1[u] + f2[u])/2);
		return;
	}
	
	vector<int> d;
	d.push_back(f2[u]);
	for(auto v : adj[u]) {
		if(v == par) continue;
		dfs3(v, u);
		d.push_back(f1[v]);
	}
	
	sort(d.begin(), d.end());
	int sum = 0;
	for(auto x : d) sum += x;
	
	ok &= (sum == p[u]*2 && d[sz(d) - 1]*2 <= sum);
	db(ok);
	cerr << "\n";
}

signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int root = -1;
	
	for(int i = 1; i <= n; ++i) {
		if(sz(adj[i]) == 1) continue;
		root = i;
		break;
	}
	
	dfs1(root, -1);
	dfs2(root, -1);
	dfs3(root, -1);
	
	cout << (ok ? "YES\n" : "NO\n");
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}