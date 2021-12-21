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
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

set<int> st1,st2;
int ans,n,u,v;
void solve() {
	st1.clear();
	st2.clear();
	cin >> n;	
	vector<int> a[n+1],b[n+1];
	for(int i=1;i<=n;++i) {
		cin >> u >> v;
		a[u].pb(v);
		st1.insert(u);
		b[v].pb(u);
		st2.insert(v);
	}
	ans = (n-2)*(n-1)*n/6;
	for(auto t : st1) {
		int st = a[t].size();
		if(st > 2) ans -= (st-2)*(st-1)*st/6;
	}
	for(auto t : st2) {
		int st = b[t].size();
		if(st > 2) ans -= (st-2)*(st-1)*st/6;
	}
	cout << ans;
	
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