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
const long long inf = 1e18;

int n,k;
int st[4*MAXN1];
int lazy[4*MAXN1];
int a[MAXN1];
int dp[MAXN1];


void pushdown(int id, int l, int r) {
	st[id] += lazy[id];
	
	if(l != r) {
		lazy[id << 1] += lazy[id];
		lazy[id << 1|1] += lazy[id];
	}
	
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
	pushdown(id, l ,r);
	
	if(r < u || v < l) return;
	
	if(u <= l && r <= v) {
		lazy[id] += val;
		pushdown(id, l, r);
		return;
	}
	
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, val);
	update(id << 1|1, mid + 1, r, u, v, val);
	
	st[id] = max(st[id << 1], st[id << 1|1]);
	
}

int get(int id, int l, int r, int u, int v) {
	pushdown(id, l, r);
	if(r < u || v < l) return 0;
	
	if(u <= l && r <= v) {
		return st[id];
	} 
	
	int mid = (l + r) >> 1;
	return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}


signed main() {
	fast_cin();
	
	cin >> n >> k;
	++n;
	for(int i = 2; i <= n; ++i) cin >> a[i];
	int res = 0;
	
	for(int i = 2; i <= n; ++i) {
		update(1, 0, n, 0, i - 2, a[i]);
		
		dp[i] = max(get(1, 0, n, max(0LL, i - k - 1), i - 2), a[i]);
		
		update(1, 0, n, i, i, dp[i]);
		res = max(res, dp[i]);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}