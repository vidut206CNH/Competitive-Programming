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
	int  v, t, p, d;
};

int n,m,s;
vector<edge> adj[MAXN1];
int nextt[MAXN1];
bool ok[MAXN1];

bool check(int g) {
	for(int i = 0; i < n; ++i) nextt[i] = -1;
	for(int i = 0; i < n; ++i) ok[i] = false;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({g, 0});
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int u = pq.top().se;
		
		pq.pop();
		
/*		db(u);
		db(val);
		cerr << "\n";*/
		
		if(ok[u]) continue;
		ok[u] = true;
		
		for(auto x : adj[u]) {
			int V = x.v;
			int T = x.t;
			int P = x.p;
			int D = x.d;
			
			int val1 = val + max(0, T - val);
			if(val1%P <= T%P) {
				val1 += (T%P - val1%P);
			}
			else val1 += (P + T%P - val1%P);
			
			if(val1 + D > s) continue;
			
			if(nextt[V] == -1 || nextt[V] > val1 + D) {
				nextt[V] = val1 + D;
				pq.push({nextt[V], V});
			}
			
		}
	}
	//db(nextt[n - 1]);
	//cerr << "\n";
	return (nextt[n - 1] != -1);
	
}


signed main() {
	fast_cin();
	
	cin >> n >> m >> s;
	
	for(int i = 1; i <= m; ++i) {
		int  u,v,t,p,d;
		cin >> u >> v >> t >> p >> d;
		adj[u].push_back({v, t, p, d});
	}
	
	int low = 0, high = s, res = -1;
	
	while(low <= high) {
		int mid = (low + high) >> 1;
		if(check(mid)) {
			res = mid;
			low = mid + 1;
		} else high = mid - 1;
	}
	
	
	if(res == -1) cout << "impossible";
	else cout << res;
		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}