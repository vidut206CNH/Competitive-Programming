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
const int MAXN1 = 3e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,k;
int lazy[4*MAXN1];
int maxx[4*MAXN1];

void pushdown(int id, int l, int r) {
	maxx[id] += lazy[id];
	if(l != r) {
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	
	lazy[id] = 0;
}


void update(int id, int l, int r, int u, int v, int val) {
	pushdown(id, l, r);
	if(r < u || v < l) return;
	if(u <= l && r <= v) {
		lazy[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, val);
	update(id << 1|1, mid + 1, r, u, v, val);
	pushdown(id << 1, l, mid);
	pushdown(id << 1|1, mid + 1, r);
	maxx[id] = max(maxx[id << 1], maxx[id << 1|1]);
}

int get(int id, int l, int r, int u, int v) {
	pushdown(id, l, r);
	if(r < u || v < l) return 0;
	if(u <= l && r <= v) return maxx[id];
	int mid = (l + r) >> 1;
	
	return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
	
}


void query(int l, int r, int val) {
	if(l == r) {
		cout << "T\n";
		return;
	}
	--r;
	int g = get(1, 1, n, l, r);
/*	db(g);
	cerr << "\n";*/
	if(g + val <= k) {
		cout << "T\n";
		update(1, 1, n, l, r, val);
	} else {
		cout << "N\n";
	}
}

signed main() {
	fast_cin();
	
	cin >> n >> k >> m;
	
	for(int i=1;i<=m;++i) {
		int l, r, val;
		cin >> l >> r >> val;
		query(l, r, val);
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}