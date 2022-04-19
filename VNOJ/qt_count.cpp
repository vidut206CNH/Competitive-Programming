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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;


int st[3*MAXN1];
int lazy[3*MAXN1];


void pushdown(int id, int l, int r) {
	if(lazy[id] != 0) {
		st[id] = lazy[id];
	}
	
	if(l != r && lazy[id] != 0) {
		lazy[id << 1] = lazy[id];
		lazy[id << 1|1] = lazy[id];
	}
	
	
	lazy[id] = 0;
}


void update(int id, int l, int r, int u, int v, int color) {
	
	pushdown(id, l, r);
	
	
	if(u <= l && r <= v) {
		lazy[id] = color;
		pushdown(id, l, r);
		return;
	}
	
	
	int mid = (l + r) >> 1;
	if(u <= mid) update(id << 1, l, mid, u, v, color);
	if(mid + 1 <= v) update(id << 1|1, mid + 1, r, u, v, color);
	
}


int get(int id, int l, int r, int pos) {
	pushdown(id, l, r);
	
	if(l == r) {
		return st[id];
	}
	
	int mid = (l + r) >> 1;
	if(pos <= mid) return get(id << 1, l, mid, pos);
	return get(id << 1|1, mid + 1, r, pos);
	
}

signed main() {
	fast_cin();
	
	int n,m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		update(1, 1, m, u, v, i);
	}
	
	vector<bool> ok(n + 5);
	
	int res = 0;
	
	for(int i = 1; i <= m; ++i) {
		int color = get(1, 1, m, i);
		if(!ok[color] && color) res++;
		ok[color] = true;
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}