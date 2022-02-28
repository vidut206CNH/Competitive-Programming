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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int a[MAXN1];
int st[2][4 * MAXN1];


void build(int id, int l, int r) {
	if(l == r) {
		st[0][id] = st[1][id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	st[0][id] = min(st[0][id << 1], st[0][id << 1|1]);
	st[1][id] = max(st[1][id << 1], st[1][id << 1|1]);
}


pii get(int id, int l, int r, int&u, int&v) {
	if(r < u || v < l) return {inf, -inf};
	if(u <= l && r <= v) {
		return {st[0][id], st[1][id]};
	}
	
	int mid = (l + r) >> 1;
	pii left = get(id << 1, l, mid, u, v);
	pii right = get(id << 1|1, mid + 1, r, u, v);
	return {min(left.fi, right.fi), max(left.se, right.se)};
}


int find(int l, int r, int pos) {
	int res = pos;
	while(l <= r) {
		int mid = (l + r) >> 1;
		pii cur = get(1, 1, n, mid, pos);
		if(cur.se - cur.fi <= k) {
			res = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	
	return res;
}



signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		res += (i - find(1, i, i) + 1);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}