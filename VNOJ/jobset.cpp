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
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;
int a[MAXN1];
vector<int> adj[MAXN1];


void dfs(int u, int &sum, vector<bool> &ok) {
/*	db(u);
	db(sum);
	cerr << "  ";*/
	sum += a[u];
	for(auto x : adj[u]) {
		if(ok[x]) continue;
		
		ok[x] = true;
		dfs(x, sum, ok);
	}
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	cin >> m;
	for(int i=1;i<=m;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	
	int res = 0;
	for(int i=1;i<=n;++i) {
		int sum = 0;
		vector<bool> visited(n + 1, false);
		
		visited[i] = true;		
		dfs(i, sum, visited);
		// cerr << "\n";
		for(int j = 1; j <= n; ++j) {
			
			if(visited[j]) continue;
			
			vector<bool> ok = visited;
			
			int tmp = 0;
			ok[j] = true;
			dfs(j, tmp, ok);
/*			cerr << '\n';
			db(i);
			db(j);
			db(tmp);
			db(sum);
			cerr << "\n\n";*/
			if(tmp > 0) {
				visited = ok;
				sum += tmp;
			}
		}
		
		res = max(res, sum);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}