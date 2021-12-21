/* 
	link problem: 
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
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int n,m,u,v;
vector<int> adj[2005];
set<int> ans;
int visit[2005];
void dfs(int r, int u) {
	for(auto x : adj[u]) {
		if(visit[u] != r && x==r) {
			ans.insert(r);
			return;
		}
		else {
			visit[x] = u;
			dfs(r,x);
		}
	}
	cout << u << ' ';
}

void solve() {
	cin >> n >> m;
	for(int i=1;i<=m;++i) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1;i<=n;++i) {
		memset(visit,0,sizeof(visit));
		visit[i] = i;
		dfs(i,i);
		cout << ans.size() << '\n';
	}
	cout << ans.size();
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}