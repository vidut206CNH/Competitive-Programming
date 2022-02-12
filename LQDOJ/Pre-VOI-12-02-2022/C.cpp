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
const int MAXN1 = 5e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,q;
vector<int> adj[MAXN1];
int p[MAXN1];
bool bag[MAXN1];
int h[MAXN1];


void dfs(int par, int u) {
	for(auto x : adj[u]) {
		if(x == par) continue;
		h[x] = h[u] + 1;
		dfs(u, x);
	}
}

void sub1() {
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int u;
			cin >> u;
			bag[u] ^= 1;
		} else {
			int u;
			cin >> u;
			memset(h, 0, sizeof h);
			dfs(0, u);
			
			int minn = 1e9,cnt = 0;
			
			for(int i = 1; i <= n; ++i) {
				if(bag[i]) {
					if(minn > h[i]) {
						cnt = 0;
						minn = h[i];
					}
					
					if(minn == h[i]) {
						cnt++;
					}
				}
			}
			cout << minn << " " << cnt << "\n";
		}
	}
}

signed main() {
	fast_cin();
	cin >> n >> m >> q;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1; i <= m; ++i) {
		cin >> p[i];
		bag[p[i]] = true;
	}
	
	sub1();
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}