/* 
	link problem: https://oj.vnoi.info/problem/haoi11_da
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

int n,s;
pii p[nMax];

void solve() {
	cin >> n >> s;
	for(int i=1;i<=n;++i) {
		cin >> p[i].fi >> p[i].se;
	}
	sort(p+1,p+n+1);
	int i=1;
	while(i <= n && s >= p[i].fi) {
		s += p[i].se;
		i++;
	}
	for(int i=1;i<=n;++i) cout << p[i].fi << ' ' << p[i].se << '\n';
	cout << i-1;
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