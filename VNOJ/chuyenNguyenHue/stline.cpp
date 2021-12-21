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

vector< pii > p;
int n,x,y,cnt=0;

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> x >> y;
		p.pb({x,y});
	}
	sort(p.begin(),p.end());
	//for(auto t : p) cout << t.fi << ' ' << t.se << '\n';
	int cur=0,nx = 1;
	while(nx < n) {
		if(p[cur].se > p[nx].fi) {
			cnt++;
			if(p[cur].se > p[nx].se) {
				cur = nx;
				nx++;
			}
			else nx++;
		}
		else {
			if(p[cur].se < p[nx].se) cur = nx;
			nx++;
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