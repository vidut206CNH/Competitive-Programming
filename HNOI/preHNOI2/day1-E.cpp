/* 
	link problem: 
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
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e6+5;
const int MAXN2 = 2e5 + 5;

struct node{
	int v;
	int w;
};

struct path {
	int v;
	vector<int> A;
	bool operator() (path &M,path &N) {
		if(M.A.size() != N.A.size()) return M.A.size() > N.A.size();
		return M.A > N.A;
	}
};

int n,m;

vector<node> E[MAXN2];
vector< int > dist[MAXN2];
vector<bool> vis(MAXN2, 0);

bool comp(const vector<int> &A, const vector<int> &B) {
	if(A.size() != B.size()) return A.size() < B.size();
	return A < B;
}

void dijk() {
	
	priority_queue<path, vector<path>, path> p;
	p.push({1,{}});
	dist[1] = {};
	vis[1] = 1;
	vector<bool> P(MAXN2, 0);
	
	
	while(!p.empty()) {
		path curr = p.top();
		p.pop();
		
 
		
		if(P[curr.v]) continue;
		P[curr.v] = 1;
		
		for(auto edg : E[curr.v]) {
			int v = edg.v;
			int w = edg.w;
			vector<int> tmp = curr.A;
			tmp.pb(w);
			if(!vis[v] || comp(tmp, dist[v])) {
				dist[v] = tmp;
				p.push({v,dist[v]});
			}
			vis[v] = 1;
		}
	}
	
}


signed main() {
	fast_cin();
	cin >> n >> m;
	for(int i=1;i<=m;++i) {
		int u,v,w;
		cin >> u >> v >> w;
		E[u].pb({v,w});
		E[v].pb({u,w});
	}
	dijk();
	cout << dist[n].size() << "\n";
	for(auto x : dist[n]) cout << x << " ";
	
	return 0;
}