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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,s;
vector<int> adj[MAXN1];
bool f[MAXN1], visited[MAXN1];
int par[MAXN1];
int d[MAXN1];

void bfs() {
	queue<int> q;
	q.push(s);
	
	d[s] = 1;
	
	while(!q.empty()) {
		int cur = q.front();
		
		q.pop();
		
		for(auto x : adj[cur]) {

			
			if(d[x] == 0) {
				
				f[x] |= f[cur];	
				d[x] = d[cur] + 1;
				par[x] = cur;
				q.push(x);
				
			}
			
			
			else if(d[x] == d[cur] + 1 && par[x] != cur) {
				f[x] = true;
			}
			
		}
		
/*		db(cur);
		db(f[cur]);
		cerr << "\n";*/
	}
}

signed main() {
	fast_cin();
	
	cin >> n >> m >> s;
	for(int i=1;i<=m;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].emplace_back(v);
	}
	
	bfs();
	int res = 0;
	
	for(int i=1;i<=n;++i) {
		res += f[i];
	}	
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}