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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int st[4*MAXN1];
pii p[MAXN1];

void build(int id, int l, int r) {
	if(l == r) {
		st[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	st[id] = st[id << 1] + st[id << 1|1];
} 


void update(int id, int l, int r, int pos, int val) {
	if(r < pos || pos < l) return;
	if(l == r) {
		st[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, pos, val);
	update(id << 1|1, mid + 1, r, pos, val);
	st[id] = st[id << 1] + st[id << 1|1];
}

int get(int id, int l, int r, int u, int v) {
	if(r < u || v < l) return 0;
	if(u <= l && r <= v) {
		return st[id];
	}
	
	int mid = (l + r) >> 1;
	return get(id << 1, l, mid, u, v) + get(id << 1|1, mid + 1, r, u, v);
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	
	build(1, 1, n);
	
	int q;
	cin >> q;
	while(q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			
			update(1, 1, n, x, y - a[x]);
			a[x] = y;
		}
		else {
			int res = 0;
			for(int i = x; i <= y; ++i) {
				res += get(1, 1, n, p[i].fi, p[i].se);
			}
			
			cout << res << "\n";
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}