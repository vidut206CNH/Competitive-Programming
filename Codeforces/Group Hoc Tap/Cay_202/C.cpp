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

int n;
int a[MAXN1];
int f[MAXN1];
int best[2][MAXN1];
vector<int> adj[MAXN1];
int res = -inf;


void dfs(int u, int par) {
	
	vector<pair<int, pii> > p;
	int maxx1 = -inf, maxx2 = -inf;
	
	f[u] = a[u];
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		
		dfs(v, u);
		
		p.push_back({0, {f[v], v}});
		
		p.push_back({1, {best[0][v], v}});
		p.push_back({1, {best[1][v], v}});
		
		f[u] += f[v];
		
	}
	
	sort(p.begin(), p.end(), [](const pair<int, pii>& A, const pair<int, pii>& B) {
		if(A.se.fi != B.se.fi) return A.se.fi > B.se.fi;
		return A > B;
	});
	
	if(sz(p)) {
		int cnt = 0;
		int node_first = -1;
		int state = -1;
		
		for(auto x : p) {
			
			if(cnt == 2) break;
			
			int state1 = x.fi;
			int val = x.se.fi;
			int node = x.se.se;
			
			if(node_first == -1) {
				maxx1 = val;
				node_first = node;
				state = state1;
				cnt++;
				continue;
			}
			
			if(node == node_first && state != state1) continue;
			
			maxx2 = val;
			cnt++;
		}
		
	}
	
	best[0][u] = maxx1;
	best[1][u] = maxx2;
	
	if((best[0][u] != -inf) && (best[1][u] != -inf)) res = max(res, best[0][u] + best[1][u]);
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, -1);
	
	if(res == -inf) cout << "Impossible";
	else cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}