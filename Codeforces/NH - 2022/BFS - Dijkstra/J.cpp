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
const int MAXN1 = 1005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,lim;
int w[MAXN1];
vector<int> adj[MAXN1];
int last[MAXN1];
int nextt[MAXN1];
int res[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> w[i];
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	cin >> lim;
	
	
	// dijkstra
	memset(last, -1, sizeof last);
	memset(nextt, -1, sizeof nextt);
	priority_queue<pii, vector<pii >, greater<pii > > pq;
	
	
	pq.push({0, 1});
	nextt[1] = 0;
	
	while(!pq.empty()) {
		int node = pq.top().se;
		int val = pq.top().fi;
/*		db(node);
		db(val);
		cerr << '\n';*/
		pq.pop();
		
		if(val > lim) break;
		
		res[node]++;
		
		for(auto x : adj[node]) {
			if((last[x] == -1 || last[x] < val) && (nextt[x] < val || nextt[x] == -1)) {
				nextt[x] = val + w[x];
				pq.push({nextt[x], x});
			}
		}
		
		
		last[node] = val;
	}
	
	for(int i = 1; i <= n; ++i) cout << res[i] << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}