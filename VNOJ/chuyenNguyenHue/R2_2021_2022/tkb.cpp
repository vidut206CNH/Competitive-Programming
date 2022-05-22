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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int f[2][MAXN1];
int s[2][MAXN1];
vector<int> adj[MAXN1];

void dfs1(int u, int par) {
	vector<pii> p;
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		
		dfs1(v, u);
		p.push_back({f[0][v], v});
	}
	
	if(sz(p) == 0) return;
	
	sort(p.begin(), p.end(), greater<pii>());
	
	int sum = 0;
	int cnt = 0;
	
	for(int i = 0; i < min(sz(p), k); ++i) {
		sum += p[i].fi;
		cnt++;
	}
	
	for(int i = 0; i < sz(p); ++i) {
		int v = p[i].se;
		
		f[1][u] = max(f[1][u], sum + f[1][v] - (i < k ? f[0][v] : f[0][p[k - 1].se]));
	}
	
	
	if(cnt == k) {
		f[0][u] = (sum - p[k - 1].fi + 2*(cnt - 1));
		f[1][u] += (2*cnt - 1);
	}
	
	else {
		f[0][u] = (sum + 2*cnt);
		f[1][u] += (2*cnt - 1);
	}
	
	
}

signed main() {
	fast_cin();
	
	
	cin >> n >> k;
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int res = 0;
	
	//dfs1(3, -1);
	
	for(int root = 1; root <= n; ++root) {
		memset(f, 0, sizeof f);
		
		dfs1(root, -1);
		
		res = max(res,max(f[0][root], f[1][root]));
	}
	
	cout << res;
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}