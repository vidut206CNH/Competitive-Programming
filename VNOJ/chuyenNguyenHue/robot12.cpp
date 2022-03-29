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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,b,r;
vector<int> adj[MAXN1];
vector<int> robots;
int res[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> m >> b >> r;
	memset(res, -1, sizeof res);
	queue<int> q;
	for(int i = 1; i <= b; ++i) {
		int x;
		cin >> x;
		q.push(x);
		res[x] = 0;
	}
	
	for(int i = 1; i <= r; ++i) {
		int x;
		cin >> x;
		robots.push_back(x);
	}
	
	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	while(!q.empty()) {
		int u = q.front();
		
		q.pop();
		
		for(auto v : adj[u]) {
			if(res[v] == -1) {
				res[v] = res[u] + 1;
				q.push(v);
			}
		}
	}
	
	for(auto x : robots) cout << res[x] << " ";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}