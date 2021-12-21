/* 
	link problem: https://oj.vnoi.info/problem/kquery
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


vector< pair<int,pii> > query;
int a[nMax];
int n,q,k,l,r;

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	cin >> q;
	for(int i=1;i<=q;++i) {
		cin >> l >> r >> k;
		query.pb({k,{l,r}});  
	}
	sort(query.begin(),query.end());
	for(auto x : query) {
		cout << x.fi << ' ' << x.se.fi << ' ' << x.se.se << '\n';
	}
	
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