/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
//const int inf = 1e18;

vector<int> adj[MAXN1];
int dist[MAXN1];
bool P[MAXN1];
int n,m;
pii E[105];
map<int,int> F;
int f[MAXN1];
int lim;


void dijk() {
	
	dist[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii > > pq;
	pq.push({0, 0});
	
	while(!pq.empty()) {
		int u = pq.top().se;
		int val = pq.top().fi;
		
		pq.pop();
		
		if(P[u]) continue;
		P[u] = true;
		
		for(auto v : adj[u]) {
			int val1 = dist[v];
			
			if(val1 == -1 || val1 > val) {
				dist[v] = val;
				pq.push({val, v});
			}
		}
		
		
		if(u != 0) {
			int v = u - 1;
			
			int val1 = dist[v];
			
			if(val1 == -1 || val1 > val + f[u] - f[v]) {
				dist[v] = val + f[u] - f[v];
				pq.push({val + (f[u] - f[v]), v});
			}
		}
		
		if(u + 1 <= lim) {
			int v = u + 1;
			int val1 = dist[v];
			
			if(val1 == -1 || val1 > val + f[v] - f[u]) {
				dist[v] = val + f[v] - f[u];
				pq.push({val + f[v] - f[u], v});
			}
		}
		
		
		
	}
}


signed main() {
	fast_cin();
	int t;
	cin >> t;
	memset(dist, -1, sizeof dist);
	
	while(t--) {
		cin >> n >> m;
		memset(P, false, sizeof P);
		F.clear();
		lim = 0;
		
		set<int> st;
		st.insert(0);
		for(int i = 1; i <= m; ++i) {
			int rem, M;
			cin >> rem >> M;
			E[i] = {rem, M};
			for(int k = 0; (rem + k*M) < n; ++k) {
				int u = rem + k*M;
				st.insert(u);
			}
		}
		
		for(auto u : st) {
			f[++lim] = u;
			F[u] = lim;
		}
		
		for(int i = 1; i <= m; ++i) {
			pii x= E[i];
			int rem = x.fi;
			int M = x.se;
			
			for(int k = 0; rem + k*M < n; ++k) {
				int U = rem + k*M;
				int u = F[U];
				if(k > 0) adj[u].push_back(F[U - M]);
				if(U + M < n) adj[u].push_back(F[U + M]);
				 
			}
		}
		
		
		dijk();
		
		int best = 0, floor = 0;
		
		for(int u = 0; u < lim; ++u) {
			
			int U = f[u];
			int w_u = dist[u];
			int V = f[u + 1];
			int w_v = dist[u + 1];
			
			if((w_u + w_v + V - U)/2 > best) {
				best = (w_u + w_v + V - U)/2;
				floor = U + (best - w_u);
			}
		}
		
		int last = lim;
		//while(last > 0 && sz(adj[last]) == 0) --last;
		
		//db(f[last]);
		if(best < (n - 1 - f[last]) + dist[last]) {
			best = (n - 1 - f[last]) + dist[last];
			floor = n - 1; 
		}
		
		//reset
		for(int i = 0; i <= lim; ++i) adj[i].clear();
		for(int i = 0; i <= lim; ++i) dist[i] = -1;
		cout << best << " " << floor << "\n";
	}
		
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}