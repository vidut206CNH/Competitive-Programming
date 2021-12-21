/* 
	link problem: https://oj.vnoi.info/problem/haoi10_ck
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

int n,p,ans=1,t;
int a[nMax],mark[105];

pii st[2*nMax];



void build(int id,int l,int r) {
	if(l == r) {
		st[id] = {a[l],a[l]};
		return;
	}
	int mid = (l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].fi = min(st[id*2].fi,st[id*2+1].fi);
	st[id].se = max(st[id*2].se,st[id*2+1].se);
}

pii query(int id,int u,int v,int l,int r) {
	if(u > r || v < l) {
		return {MAXX,MINN};
	}
	if(u <= l && r <= v) {
		return st[id];
	}
	int mid = (l+r)/2;
	pii tm1 = query(id*2,u,v,l,mid);
	pii tm2 = query(id*2+1,u,v,mid+1,r);
	return {min(tm1.fi,tm2.fi),max(tm1.se,tm2.se)};
}
//solve 1: fail
void solve1() {
	cin >> n >> p;
	for(int i=1;i<=n;++i) cin >> a[i];
	build(1,1,n);
	for(int i=1;i<=n;++i) {
		query(1,1,i,1,n);
		query(1,i,n,1,n);
	}
}

int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve1();
		cout << '\n';
		--t;
	}
	return 0;
}