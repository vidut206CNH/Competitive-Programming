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
const int MAXN2 = 2e5;

int n,k,q;
long long st[4*MAXN1];
long long lazy[4*MAXN1];
int f[MAXN1];

void pushdown(int id, int l, int r) {
	st[id] += (r - l + 1)*lazy[id];
	
	if(l != r) {
		lazy[id << 1] += lazy[id];
		lazy[id << 1|1] += lazy[id];
	}
	
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v) {
	pushdown(id, l, r);
	if(r < u || v < l) return;
	
	if(u <= l && r <= v) {
		lazy[id] += 1;
		pushdown(id, l, r);
		return;
	}
	
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v);
	update(id << 1|1, mid + 1, r, u, v);
	
	st[id] = st[id << 1] + st[id << 1|1];
}


long long get(int id, int l, int r, int pos) {
	pushdown(id, l, r);
	if(pos < l || r < pos) return 0;
	
	if(l == r) {
		return st[id];
	}
	
	int mid = (l + r) >> 1;
	return get(id << 1, l, mid, pos) + get(id << 1|1, mid + 1, r, pos);
}

int main() {
	fast_cin();
	
	cin >> n >> k >> q;
	
	
	for(int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		update(1, 1, MAXN2, l, r);
	}
	
	for(int i = 1; i < MAXN1; ++i) {
		f[i] = f[i - 1] + (get(1, 1, MAXN2, i) >= k);
		//if(90 <= i && i <= 100) db(f[i]);
	}
	
	while(q--) {
		int l,r;
		cin >> l >> r;
		cout << f[r] - f[l - 1] << "\n";
	}
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}