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
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	
	int res = 0, suma = 0;
	
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 1) {
			res++;
			color[i] = 1;
			for(auto x : adj[i]) {
				color[x] = 1;
			}
		}
	}
	
	priority_queue<pair<int, pii >, vector<pair<int, pii > >, greater< pair<int, pii > > > p;
	
	for(int i = 1; i <= n; ++i) {
		if(color[i]) continue;
		deg[i] = 0;
		for(auto x : adj[i]) {
			if(color[x]) continue;
			deg[i]++;
		}
		
		p.push({1, {deg[i], i}});
	}
	
	pii cur;
	
	
	while(!p.empty()) {
		bool ok = p.top().fi;
		int val = p.top().se.fi;
		int node = p.top().se.se;
		p.pop();
/*		db(node);
		db(val);
		cerr << "\n";*/
		
		if(color[node]) continue;
		
		res += ok;
		if(ok == false) {
			
			color[node] = 1;
			for(auto v : adj[node]) {
				--deg[v];
				p.push({1, {deg[v], v}});
			}
			continue;
			
		}
		
		int sum = 0;
		
		for(auto v : adj[node]) {
			if(color[v]) sum += color[v];
			else {
				sum += 1;
				p.push({0, {deg[v], v}});
			}
		}
		
		color[node] = sum;
		
	}
	
	for(int i = 1; i <= n; ++i) suma += color[i];
	
	cout << res << " " << suma << "\n";
	for(int i = 1; i <= n; ++i) cout << color[i] << " ";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}