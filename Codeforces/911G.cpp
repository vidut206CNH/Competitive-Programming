/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
//const int inf = 1e18;



int n,q;
int st[3*MAXN1][103];
//int lazy[3*MAXN1][103];
int res[MAXN1];
int a[MAXN1];

void build(int id, int l ,int r) {
	if(l == r) {
		for(int i = 1; i <= 100; ++i) {
			st[id][i] = i;
		}
		return;
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	for(int i = 1; i <= 100;++i) {
		st[id][i] = i;
	}
}



void pushdown(int id, int l, int r) {
	if(l != r) {
		for(int i = 1; i <= 100; ++i) {
			
			lazy[id << 1][i] = lazy[id][i];
			lazy[id << 1|1][i] = lazy[id][i];
			
		}
		ok[id << 1] = false;
		ok[id << 1|1] = false;
	}
	ok[id] = true;
}


void update(int id, int l, int r, int u, int v, int oval, int nval) {
	pushdown(id, l, r);
	if(r < u || v < l) return;
	if(u <= l && r <= v) {
		ok[id] = false;
		for(int i = 1; i <= 100; ++i) {
			if(lazy[id][i] == oval) lazy[id][i] = nval;
		}
		pushdown(id, l, r);
		return;
	}
	
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, oval, nval);
	update(id << 1|1, mid + 1, r, u, v, oval, nval);
}

void get(int id, int l, int r, int pos) {
	pushdown(id, l, r);
	if(pos < l || pos > r) return;
	if(l == r) {
		res[pos] = lazy[id][a[pos]];
		return;
	}
	int mid = (l + r) >> 1;
	get(id << 1, l, mid, pos);
	get(id << 1|1, mid + 1, r, pos);

}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	build(1, 1, n);
	
	cin >> q;
	while(q--) {
		int l,r,x,y;
		cin >> l >> r >> x >> y;
		update(1, 1, n, l, r, x, y);
		for(int i = 1; i <= n; ++i) {
			get(1, 1, n, i);
			cout << res[i] << " \n"[i == n];
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}