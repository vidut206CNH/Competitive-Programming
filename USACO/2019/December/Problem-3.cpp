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
vector<int> adj[MAXN1];
int comp[MAXN1];
string s;

int num = 1;

void dfs(int cur) {
	if(comp[cur]) return;
	comp[cur] = num;
	for(auto x : adj[cur]) {
		if(s[x] == s[cur]) dfs(x);
	}
}


signed main() {
	fast_cin();
	
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	
	
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i=1;i<n;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}		
	
	for(int i=1;i<=n;++i) {
		if(!comp[i]) {
			dfs(i);
			++num;
		}
	}
	
	for(int i=1;i<=m;++i) {
		int u,v;
		char c;
		cin >> u >> v >> c;
		if(s[u] == c || comp[u] != comp[v]) cout << 1;
		else cout << 0;
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}