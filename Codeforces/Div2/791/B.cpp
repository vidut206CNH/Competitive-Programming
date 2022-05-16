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

int t;
int n,q;
int a[MAXN1];
int st[4*MAXN1];
int lazy[4*MAXN1];

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


void pushdown(int id, int l, int r) {
	if(lazy[id] == 0) continue;
	
	st[id] = (r - l + 1)*lazy[id];
	if(l != r) {
		lazy[id << 1] = lazy[id];
		lazy[id << 1|1] = lazy[id];
	}	
	
	lazy[id] = 0;
}



signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> n >> q;
		memset(st, 0, sizeof(st[0])*(4*n));
		
		for(int i = 1; i <= n; ++i) cin >> a[i];
		
		build(1, 1, n);
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}