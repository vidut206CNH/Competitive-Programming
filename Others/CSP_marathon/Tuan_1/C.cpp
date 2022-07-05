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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e9 + 888;

int n;
int a[MAXN1];
int R[MAXN1];
int L[MAXN1];
int occ[MAXN1];
int st[4*MAXN1];
int lazy[4*MAXN1];



void pushdown(int id, int l, int r) {
	if(l != r) {
		lazy[id << 1] = min(lazy[id << 1], lazy[id]);
		st[id << 1] = min(st[id << 1], lazy[id]);
		lazy[id << 1|1] = min(lazy[id << 1|1], lazy[id]);
		st[id << 1|1] = min(st[id << 1|1], lazy[id]);
	}
	lazy[id] = inf;
}


void update(int id, int l, int r, int u, int v, int val) {
	if(r < u || v < l) return;
	
	if(u <= l && r <= v) {
		lazy[id] = min(lazy[id], val);
		st[id] = min(st[id], val);
		return;
	}
	
	int mid = (l + r) >> 1;
	pushdown(id, l, r);
	update(id << 1, l, mid, u, v, val);
	update(id << 1|1, mid + 1, r, u, v, val);
	
	st[id] = max(st[id << 1], st[id << 1|1]);
}


int get(int id, int l, int r, int u, int v) {
	if(r < u || v < l) return -inf;
	
	if(u <= l && r <= v) return st[id];
	
	pushdown(id, l, r);
	int mid = (l + r) >> 1;
	return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}


void solve() {
	memset(st, 0x3f, sizeof st);
	memset(lazy, 0x3f, sizeof lazy);
	memset(occ, 0, sizeof occ);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		L[i] = occ[a[i]];
		occ[a[i]] = i;	
	}
	
	// reset
	for(int i = 1; i <= n; ++i) occ[a[i]] = n + 1;
	
	bool bad = false;
	for(int i = n; i >= 1; --i) {
		
		R[i] = occ[a[i]];
		occ[a[i]] = i;
		
		update(1, 1, n, i, R[i] - 1, L[i]);
		
		if(get(1, 1, n, i, n) >= i) {
			bad = true;
			break;
		}
		
	}
	
	cout << (bad ? "NO\n" : "YES\n");
}

int main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}