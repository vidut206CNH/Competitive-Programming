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

int n,q;
int st[3*MAXN1];
int sum[3*MAXN1];
int lazy[3*MAXN1];

int a[MAXN1];
int f[MAXN1];

void build(int id, int l, int r) {
	if(l == r) {
		st[id] = f[l];
		sum[id] = f[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	st[id] = min(st[id << 1], st[id << 1|1]);
	sum[id] = sum[id << 1] + sum[id << 1|1];
}


void pushdown(int id, int l, int r) {
	st[id] += lazy[id];
	sum[id] += lazy[id]*(r - l + 1);
	if(l != r) {
		lazy[id << 1] += lazy[id];
		lazy[id << 1|1] += lazy[id];
	}	
	lazy[id] = 0;
}


void update(int id, int l, int r, int u, int v, int val) {
	pushdown(id, l, r);
	if(r < u || v < l) return;
	if(u <= l && r <= v) {
		lazy[id] += val;
		pushdown(id, l, r);
		return;
	}
	
	int mid = (l + r) >> 1;
	
	update(id << 1, l, mid , u, v, val);
	update(id << 1|1, mid + 1, r, u, v, val);
	
	st[id] = min(st[id << 1], st[id << 1|1]);
	sum[id] = sum[id << 1] + sum[id << 1|1];
}

int get_min(int id, int l, int r, int u, int v) {
	pushdown(id, l, r);
	if(r < u || v < l) return inf;
	if(u <= l && r <= v) {
		return st[id];
	}
	
	int mid = (l + r) >> 1;
	return min(get_min(id << 1, l, mid, u, v), get_min(id << 1|1, mid + 1, r, u, v));
}


int get_sum_range(int id, int l, int r, int u, int v) {
	if(l > r) return 0;
	pushdown(id, l, r);
	if(r < u || v < l) return 0;
	if(u <= l && r <= v) return sum[id];
	int mid = (l + r) >> 1;
	return get_sum_range(id << 1, l, mid, u, v) + get_sum_range(id << 1|1, mid + 1, r, u, v);
}

int get_sum_pos(int pos) {
	return get_sum_range(1, 1, n, 1, pos) - get_sum_range(1, 1, n, 1, pos - 1);
}

int calc(int l, int r) {
	int sums = get_sum_pos(r) - get_sum_pos(l - 1);
	bool good = (sums == 0 && (get_min(1, 1, n, l, r) - get_sum_pos(l - 1)) >= 0);
	return good;
}


signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		a[i] = (c == '(' ? +1 : -1);
		f[i] = a[i] + f[i - 1];
	}	
	
	build(1, 1, n);
	
	
	while(q--) {
		int type;
		cin >> type;
		if(type == 0) {
			int pos;
			char c;
			cin >> pos >> c;
			int val = (c == '(' ? +1 : -1);
			if(val == 1) {
				if(a[pos] != val) update(1, 1, n, pos, n, 2);
			}
			else {
				if(a[pos] != val) update(1, 1, n, pos, n, -2);
			}
			a[pos] = val;
		} else {
			int l,r;
			cin >> l >> r;
			//cerr << get_sum_pos(r - 1) << " " << get_sum_pos(r) << "\n";
			cout << calc(l, r);
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}