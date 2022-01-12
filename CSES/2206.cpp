/* 
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
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
int st[2][3*MAXN1];
int a[MAXN1];



void build(int id, int l, int r) {
	if(l == r) {
		st[0][id] = a[l] - l;
		st[1][id] = a[l] + l;
/*		db(l);
		db(st[0][id]);
		db(st[1][id]);
		cerr << "\n";*/
		return;
	}
	int mid = (l+r)>> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	st[0][id] = min(st[0][id << 1], st[0][id << 1|1]);
	st[1][id] = min(st[1][id << 1], st[1][id << 1|1]);
}

void update(int id,int l, int r, int& pos, int& val) {
	if(l == r) {
		int d = (st[0][id] + st[1][id])/2;
		d = val - d;
		st[0][id] += d;
		st[1][id] += d;
		return;
	}
	
	int mid = (l + r) >> 1;
	if(pos <= mid) update(id << 1, l, mid, pos, val);
	else update(id << 1|1, mid + 1, r, pos, val);
	
	st[0][id] = min(st[0][id << 1], st[0][id << 1|1]);
	st[1][id] = min(st[1][id << 1], st[1][id << 1|1]);
}

int get(bool choose, int id, int l, int r,int u, int v) {
	if(u > v) return inf;
	if(u <= l && r <= v) {
		return st[choose][id];
	}
	int mid = (l+r) >> 1;
	int res = inf;
	if(u <= mid) res = min(res, get(choose, id << 1, l, mid, u, v));
	if(mid + 1 <= v) res = min(res, get(choose, id << 1|1, mid+1, r, u, v));
	return res;
	
}



signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	build(1,1,n);
	
	for(int i=1;i<=q;++i) {
		int t;
		cin >> t;
		if(t==1) {
			int pos,val;
			cin >> pos >> val;
			update(1,1,n,pos,val);
		} 
		else {
			int pos;
			cin >> pos;
			int res = inf;
			if(pos > 1) res = min(res, pos + get(false, 1, 1, n, 1, pos));
			if(pos < n) res = min(res, get(true, 1, 1, n, pos + 1, n) - pos);
			cout << res << "\n";
		}
	}		
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}