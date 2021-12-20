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

pair<pii, bool> p[1005];
bool mark[1005];
int n;
void solve() {
	cin >> n;
	mark[1] = 0;
	for(int i=2;i<=n;++i) {
		cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se;
	}
	sort(p+1,p+n+1);
	for(int i=2;i<=n;++i) {
		mark[i] = p[i].se^mark[i-1];
	}
	cout << mark[n];
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