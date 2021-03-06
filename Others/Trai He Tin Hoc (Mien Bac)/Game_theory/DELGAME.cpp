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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,m,k;
vector<int> adj[MAXN1];
bool ok[MAXN1];
int tot = 0;
int cnt = 0;
void dfs(int u) {
	cnt++;
	ok[u] = true;
	tot += sz(adj[u]);
	for(int v : adj[u]) {
		if(ok[v]) continue;
		
		dfs(v);
	}
}


int main() {
	fast_cin();
	
	
	while(cin >> n >> m >> k) {
		for(int i = 1; i <= n; ++i) adj[i].clear();
		memset(ok, false, sizeof ok);
		for(int i = 1; i <= m; ++i) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}	
		int nim = 0;
		for(int i = 1; i <= n; ++i) {
			if(ok[i]) continue;
			tot = 0;
			cnt = 0;
			dfs(i);
			tot /= 2;
			tot -= (cnt - 1);
			nim ^= (tot%(k + 1));
		}
		
		cout << (nim != 0) << "\n";	
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}