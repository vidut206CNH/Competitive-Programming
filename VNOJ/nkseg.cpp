/*
	link problem:
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6 + 5;

int a[nMax], pref[2*nMax], tmp, cnt = 0;
int st[4*nMax];

void build(int id,int l,int r) {
	if(l == r) {
		st[id] = pref[l];
		return;
	}
	int mid = (l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id] = min(st[id*2],st[id*2+1]);
}
int query(int id,int u,int v,int l,int r) {
	if(u > r || v < l) return INF;
	if(u <= l && r <= v) return st[id];
	int mid = (l+r)/2;
	return min(query(id*2,u,v,l,mid), query(id*2+1,u,v,mid+1,r));
}
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	for(int i=n+1;i<=2*n;++i) {
		pref[i] = pref[i-1] + a[i%n + n*(i==n)];
	}
	build(1,1,2*n);
	for(int i=0;i<=n-1;++i) {
		tmp = query(1,i+1,2*n,1,2*n);
		if(tmp > pref[i]) cnt++;
	}
	cout << cnt;
	
	
}
void solve2() {
	int n;
	cin >> n;
	for (int i = 1; i <= 2*n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
		if(i <= n) pref[i] += a[i];
		else pref[i] += a[i%n + n*(i==n)];
	}
	
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}