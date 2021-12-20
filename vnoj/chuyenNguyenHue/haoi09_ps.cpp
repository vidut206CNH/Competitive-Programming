/* 
	link problem: httf://oj.vnoi.info/problem/haoi09_f
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

typedef pair<int,int> ps;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int m,n,k;
int a[305],b[305];
vector< ps> f;

bool cmp(const ps& a, const ps& b) {
	return (a.fi*b.se < a.se*b.fi);
}

void solve() {
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=m;++i) cin >> b[i];
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			int t = __gcd(a[i],b[j]);
			f.pb({a[i]/t,b[j]/t});
		}
	}
	sort(f.begin(),f.end(),cmp);
	for(int i=0;i<n*m;++i) {
		if(i < n*m-1 && f[i] == f[i+1]) continue;
		k--;
		if(k==0) {
			cout << f[i].fi << ' ' << f[i].se;
			return;
		}
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