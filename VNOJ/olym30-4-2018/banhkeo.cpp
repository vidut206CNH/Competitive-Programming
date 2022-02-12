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

int n,m,k;
vector<pii > adj[MAXN1];
int p[25];
bool visited[MAXN1];

void bfs(int u, int cost) {
	queue<int> q;
	q.push(u);
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		
		if(visited[node]) continue;
		visited[node] = true;
		
		for(auto ed : adj[node]) {
			int v = ed.fi;
			int c = ed.se;
			if(cost <= c) {
				q.push(v);
			}
		}
	}
}

signed main() {
	fast_cin();
	
	freopen("banhkeo.inp", "r", stdin);
	freopen("banhkeo.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i=1;i<=k;++i) cin >> p[i];
	sort(p + 1, p + k + 1);
	
	
	for(int i=1;i<=m;++i) {
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	int res = 0;
	for(int i=1;i<=n;++i) {
		if(visited[i] == false) {
			bfs(i, p[1]);
			res++;
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}