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

int n,ans=0,d,ed;
pii p[nMax];

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> p[i].fi >> d;
		p[i].se = p[i].fi + d-1; 
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i) {
		if(i == 1 || p[i].fi > p[i-1].se) {
			ans += p[i].se - p[i].fi + 1;
			ed = p[i].se;
		}
		else {
			if(p[i].se > ed) {
				ans += p[i].se - ed;
				ed = p[i].se;
			}
		}
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