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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int k;
vector<pii > adj[MAXN1];


signed main() {
	fast_cin();
	
	cin >> k;	
	
	for(int node = 0; node < k; ++node) {
		for(int d = 0; d < 10; ++d) {
			int next = (node*10 + d)%k;
			adj[node].push_back({next, d});
		}
	}
	
	vector<int> dist(k + 5, inf);
	vector<bool> P(k + 5, false);
	dist[k] = 0;
	for(int i = 1; i < 10; ++i) adj[k].push_back({i%k, i});
	priority_queue<pii, vector<pii >, greater<pii > > pq;
	pq.push({0, k});
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int cur = pq.top().se;
		pq.pop();
		
		
		if(P[cur]) continue;
		P[cur] = true;
		
		for(auto x : adj[cur]) {
			int v = x.fi;
			int w = x.se;

			if(dist[v] > val + w) {
				dist[v] = val + w;
				pq.push({dist[v], v});
			}
		}
	}
	
	
	cout << dist[0];
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}