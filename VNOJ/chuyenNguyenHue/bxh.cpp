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
typedef pair<int, pii > piii;
const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int n;
piii p[nMax];

bool cmp(const piii &a, const piii &b) {
	return(a.se.fi < b.se.fi);
}

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		p[i].fi = i;
		cin >> p[i].se.fi;
		p[i].se.se = 0;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=n;i>0;--i) {
		if(p[i].se.fi == p[i+1].se.fi) p[i].se.se = p[i+1].se.se;
		else p[i].se.se = n-i+1;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i) {
		cout << p[i].se.se << ' ';
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