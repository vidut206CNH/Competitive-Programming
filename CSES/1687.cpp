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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
vector<int> adj[MAXN1];
int up[MAXN1][21];

void dfs(int u) {
	for(auto v : adj[u]) {
		if(v == up[u][0]) continue;
		
		up[v][0] = u;
		
		for(int i = 1; i < 19; ++i) {
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		
		dfs(v);
	}
}

signed main() {
	fast_cin();
	
	cin >> n >> q;
	
	for(int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	
	dfs(1);
	
	while(q--) {
		int x,k;
		cin >> x >> k;
		for(int i = 0; i < 19; ++i) {
			if(k >> i & 1) {
				x = up[x][i];
			}
		}
		
		cout << (x == 0 ? -1 : x) << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}