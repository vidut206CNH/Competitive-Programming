/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 1e6+5;
const int MAXN2 = 1e6+5;
const int inf = 2e9;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r) {
	return l + rng() * 1LL * rng()%(r - l + 1);
}


int n,m;
vector<int> adj[MAXN1];
int color[MAXN1];
int depth[MAXN1];
int par[MAXN1];
vector<int> nodes;
int cnt_odd_cycles = 0;
int cnt[MAXN1];
int S[MAXN1][2];

void minimize(int u, int state, int val) {
	S[u][state] = min(S[u][state], val);
}


void dfs(int u) {
	color[u] = 1;
	
	
	for(int i = 0; i < 2; ++i) {
		S[u][i] = inf;
	}
	
	for(int v : adj[u]) {
		if(v == par[u]) continue;
		
		if(color[v] == 0) {
			par[v] = u;
			depth[v] = depth[u] + 1;
			
			dfs(v);
			
			for(int i = 0; i < 2; ++i) {
				minimize(u, i, S[v][i]);
			}
			
		}
		
		else if(color[v] == 1) {
			
			int p = u;
			int ss = depth[p] - depth[v] + 1;
			
			if(ss%2) {
				cnt_odd_cycles++;
				cnt[p]++;
				cnt[par[v]]--;	
			}
			
			int state = ss%2;
			
			minimize(u, state, depth[v]);
		}
	}
	color[u] = 2;
	
}


void dfs2(int u) {
	for(int v : adj[u]) {
		if(v == par[u]) continue;
		if(depth[v] != depth[u] + 1) continue;
		dfs2(v);
		cnt[u] += cnt[v];
	}
}

int main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i) {
		if(!color[i]) {
			dfs(i);
			dfs2(i);
		}
	}
	
	vector<int> ans;
	for(int u = 1; u <= n; ++u) {
		if(cnt_odd_cycles == cnt[u]) {
			bool bad = false;
/*			db(u);
			db(depth[u]);
			cerr << '\n';*/
			for(int v : adj[u]) {
				if(v == par[u]) continue;
				if(depth[v] != depth[u] + 1) continue;
				
				int best = max(S[v][0], S[v][1]);
				
/*				db(v);
				db(best);
				cerr << "\n";*/
				bad |= (best < depth[u]);
			}
			//cerr << "\n\n";
			if(!bad) ans.push_back(u);
		}
	}
	
	cout << sz(ans) << '\n';
	for(auto x : ans) cout << x << " ";
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}