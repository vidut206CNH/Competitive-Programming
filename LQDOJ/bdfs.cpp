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
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e5+5;

int n,m,cnt=0,u,v;
vector<int> ad[nMax];
bool visit[nMax];

void dfs(int i) {
	visit[i] = 1;
	for(auto x : ad[i]) {
		if(!visit[x]) {
			dfs(x);
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i=1;i<=m;++i) {
		cin >> u >> v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	for(int i=1;i<=n;++i) {
		if(!visit[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
	
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}