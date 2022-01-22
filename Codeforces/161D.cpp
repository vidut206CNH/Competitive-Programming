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
const int MAXN1 = 5e4+1;
const int MAXN2 = 501;
const int inf = 1e18;


int n,k;
vector<int> adj[MAXN1];
vector<int> res(MAXN1,0);
vector< vector<int> > f(MAXN2, vector<int>(MAXN1,0));
bool visited[MAXN1];
int trace[MAXN1];

//calculate f[k][v]:
void dfs1(int cur = 1) {
	
	f[0][cur] = 1;
	
	for(auto x : adj[cur]) {
		if(trace[x] != 0) continue;
		trace[x] = cur;
		dfs1(x);
		
		for(int d = 1;d <= k;++d) {
			if(f[d-1][x] == 0) break;
			f[d][cur] += f[d-1][x];	
		}
	}
	
	for(auto x : adj[cur]) {
		if(trace[x] != cur) continue;
		
		for(int d = 1;d < k;++d) {
			
			if(f[d-1][x] == 0) break;
			
			res[cur] += (f[d - 1][x]*f[k - d][cur]);
			res[cur] -= f[d-1][x]*f[k - d - 1][x];
		}
	}
	//db(cur);
	res[cur] /= 2;
	//db(res[cur]);
	res[cur] += f[k][cur];
	//db(res[cur]);
	//cerr << "\n";
}



signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=1;i<n;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if(k == 1) {
		cout << n-1;
		exit(0);
	}
	
	trace[1] = -1;
	dfs1();
	//dfs2();
	int ans = 0;
	for(int i=1;i<=n;++i) ans += res[i];
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}