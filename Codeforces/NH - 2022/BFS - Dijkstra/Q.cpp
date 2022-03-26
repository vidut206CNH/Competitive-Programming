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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

struct edge{
	int v, t, cost;
};

struct state{
	int u, val, rem;
};

struct comp{
	bool operator() (const state& A, const state &B) {return A.val > B.val;}
};

int n,m;
bool p[MAXN1];
vector<edge> adj[MAXN1];
int dist[MAXN1];
bool ok[MAXN1];
int sum = 0;
int best;

bool dijk(int x) {
	
	for(int i = 1; i <= n; ++i) dist[i] = -1;
	for(int i = 1; i <= n; ++i) ok[i] = false;
	
	priority_queue<state, vector<state>, comp > pq;
	dist[1] = 0;
	pq.push({1, 0, x});
	
	while(!pq.empty()) {
		int u = pq.top().u;
		int val = pq.top().val;
		int rem = pq.top().rem;
		
		pq.pop();
		if(ok[u]) continue;
		ok[u] = true;
		
		if(p[u]) rem = x;
		
		for(auto ed : adj[u]) {
			
			int v = ed.v;
			int t = ed.t;
			int cost = ed.cost;
			if(rem >= cost && (dist[v] == -1 || dist[v] > t + val)) {
				dist[v] = t + val;
				pq.push({v, dist[v], rem - cost});
			}
		}
	}
	
	if(x == sum) return best = dist[n], true;
/*	db(x);
	db(dist[n]);
	cerr << "\n";*/
	return (dist[n] == best);
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> p[i];
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v,t, cost;
		cin >> u >> v >> t >> cost;
		sum += cost;
		adj[u].push_back({v, t, cost});
		adj[v].push_back({u, t, cost});
	}
	
	dijk(sum);
	
	int res = sum;
	int low = 0, high = sum;
	while(low <= high) {
		int mid = (low + high) >> 1;
		if(dijk(mid)) {
			res = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}