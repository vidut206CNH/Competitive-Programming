/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int n,m;
int a[MAXN1];
int lazy[4*MAXN1];
int st[4*MAXN1][21];
int res[21];

void build(int id, int l, int r) {
	if(l == r) {
		for(int i = 0; i <= 20; ++i) {
			if(a[l] >> i & 1) st[id][i]++;
		}
		
		return;
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	
	for(int i = 0; i <= 20; ++i) st[id][i] = st[id << 1][i] + st[id << 1|1][i];
}

void pushdown(int id, int l, int r) {
	for(int i = 0; i <= 20; ++i) {
		if(lazy[id] >> i & 1) st[id][i] = (r - l + 1) - st[id][i];
	}
	
	if(l != r) {
		lazy[id << 1] ^= lazy[id];
		lazy[id << 1|1] ^= lazy[id];
	}
	
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int x) {
	pushdown(id, l, r);
	if(u > r || v < l) return;
	if(u <= l && r <= v) {
		lazy[id] ^= x;
		pushdown(id, l, r);
		return;
	}
	
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, x);
	update(id << 1|1, mid + 1, r, u, v, x);
	for(int i = 0; i <= 20; ++i) {
		st[id][i] = st[id << 1][i] + st[id << 1|1][i]; 
	}
}

void get(int id, int l, int r, int u, int v) {
	if(u > r || v < l) return;
	pushdown(id, l, r);
	
	if(u <= l && r <= v) {
		for(int i = 0; i <= 20; ++i) res[i] += st[id][i];
		return;	
	}
	
	int mid = (l + r) >> 1;
	get(id << 1, l, mid, u, v);
	get(id << 1|1, mid + 1, r, u, v);
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);
	
	cin >> m;
	while(m--) {
		int t;
		cin >> t;
		if(t == 1) {
			memset(res, 0, sizeof res);
			int l,r;
			cin >> l >> r;
			get(1, 1, n, l, r);
			long long sum = 0;
			for(int i = 0; i <= 20; ++i) {
				sum += (1LL << i)*res[i];
			}
			
			cout << sum << "\n";
		}
		else {
			int l,r,x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}