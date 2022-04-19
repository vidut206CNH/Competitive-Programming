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

int t;
int par[MAXN1];
vector<int> child[MAXN1];
int color[MAXN1];
bool vis[MAXN1];
vector<int> topo;


void dfs(int u) {
	for(auto v : child[u]) {
		dfs(v);
	}
	topo.push_back(u);
} 

signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		
		for(int i = 1; i <= n; ++i) child[i].clear();
		for(int i = 1; i <= n; ++i) color[i] = 0;
		for(int i = 1; i <= n; ++i) vis[i] = false;
		topo.clear();
		vector<int> d;
		
		for(int i = 2; i <= n; ++i) {
			int x;
			cin >> x;
			par[i] = x;
			child[x].push_back(i);
		}
		
		for(int i = 1; i <= n; ++i) {
			if(sz(child[i]) == 0) continue; 
			d.push_back(sz(child[i]));
		}
		
		sort(d.begin(), d.end(), greater<int>());
		int res = 0;
		for(int i = 0; i < sz(d); ++i) {
			res = max(res, i + d[i]);
		}
		cout << res + 1 << "\n";
		
/*		
		int res = 0;
		
		dfs(1);
		
		reverse(topo.begin(), topo.end());
		
		for(auto x : topo) {
			if(vis[x]) continue;
			res++;
			for(auto v : child[par[x]]) vis[v] = true;
		}
		cout << max(res, n - res) << "\n";*/
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}