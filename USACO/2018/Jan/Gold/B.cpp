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

int n,k;
vector<int> adj[MAXN1];
vector<int> d(MAXN1, 0);
bool dir = false;
int dist[2][MAXN1];
queue<int> q;

void bfs() {
	while(!q.empty()) {
		int cur = q.front();
		
		q.pop();
		
		
		for(auto x : adj[cur]) {
			if(dist[dir][x] == -1) {
				dist[dir][x] = dist[dir][cur] + 1;
				q.push(x);
			}
		}
	}
}


signed main() {
	fast_cin();
	
	freopen("atlarge.in", "r", stdin);
	freopen("atlarge.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);	
		adj[v].push_back(u);
	}
	
	memset(dist, -1, sizeof dist);
	
	
	vector<int> leaf;
	
	for(int i = 1; i <= n; ++i) {
		if(adj[i].size() == 1) {
			dist[dir][i] = 0;
			leaf.push_back(i);
			q.push(i);
		}
	}
	
	bfs();
	
	
	
	dir = true;
	
	q.push(k);
	dist[dir][k] = 0;
	bfs();
	
	q.push(k);
	vector<int> vis(n + 5, false);
	vis[k] = true;
	int res = 0;
	
	while(!q.empty()) {
		int cur = q.front();
		
		q.pop();
		
		if(dist[0][cur] <= dist[1][cur]) {
			res++;
			continue;
		}
		
		for(auto x : adj[cur]) {
			if(vis[x]) continue;
			vis[x] = true;
			q.push(x);
		}
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}