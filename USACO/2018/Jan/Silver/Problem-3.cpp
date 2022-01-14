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
const int MAXN1 = 5e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
vector<pii > E[MAXN1];
int cost[MAXN1];

void dfs(int cur, int par) {
	for(auto ed : E[cur]) {
		if(ed.fi == par) continue;
		cost[ed.fi] = min(cost[cur], ed.se);
		dfs(ed.fi, cur);
	}
}

signed main() {
	fast_cin();
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	
	cin >> n >> q;
	
	for(int i=1;i<n;++i) {
		int u,v,c;
		cin >> u >> v >> c;
		E[u].push_back({v,c});
		E[v].push_back({u,c});
	}
	
	for(int i=1;i<=q;++i) {
		int x,k;
		cin >> k >> x;
		cost[x] = 1e9 + 1;
		dfs(x,0);
		int res = 0;
		for(int v=1;v<=n;++v) {
			if(v == x) continue;
			res += (cost[v] >= k);
		}
		
		cout << res << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}