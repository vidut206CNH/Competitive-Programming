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

int n;
vector<int> adj[MAXN1];
int color[MAXN1];
int deg[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	priority_queue<pii, vector<pii >, greater<pii > > p;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	
	for(int i = 1; i <= n; ++i) p.push({deg[i], i});
	int res = 0, suma = 0;
	while(!p.empty()) {
		int val = p.top().fi;
		int node = p.top().se;
		p.pop();
		
		if(color[node]) continue;
		
		res++;
		int sum = 0;
		vector<int> d;
		for(auto v : adj[node]) {
			if(color[v]) sum += color[v];
			else {
				sum++;
				color[v] = 1;
				d.push_back(v);
			}
		}
		color[node] = sum;
		
		for(auto v : d) {
			for(auto x : adj[v]) {
				if(color[x]) continue;
				p.push({--deg[x], x});
			}
		}
	}
	for(int i = 1; i <= n; ++i) suma += color[i];
	
	cout << res << " " << suma << "\n";
	for(int i = 1; i <= n; ++i) cout << color[i] << " ";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}