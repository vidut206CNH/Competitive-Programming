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

int n;
int a[MAXN1];
vector<int> st[4*MAXN1];

void build(int id, int l, int r) {
	if(l == r) {
		st[id] = {a[l]};
		return;
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	
	st[id].resize(sz(st[id << 1]) + sz(st[id << 1|1]));
	merge(st[id << 1].begin(), st[id << 1].end(), st[id << 1|1].begin(), st[id << 1|1].end(), st[id].begin());
}


int get(int id, int l, int r, int u, int v, int val) {
	if(r < u || v < l) return 0;
	if(u <= l && r <= v) {
		return st[id].end()
				- lower_bound(st[id].begin(), st[id].end(), val);
	}
	
	int mid = (l + r) >> 1;
	return get(id << 1, l, mid, u, v, val) + get(id << 1|1, mid + 1, r, u, v, val);
} 

signed main() {
	fast_cin();
	
	freopen("TEST.INP", "r", stdin);
	freopen("TEST.OUT", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = n + 1; i <= 2*n; ++i) a[i] = a[i - n];
	
	
	for(int i = 1; i <= 2*n; ++i) {
		a[i] = i - a[i];
	}
	
	build(1, 1, 2*n);
	
	int res_id = -1, best = 0;
	for(int i = 1; i <= n; ++i) {
		int val = get(1, 1, 2*n, i, i + n - 1, i);
		if(val > best) {
			best = val;
			res_id = i;
		}
	}
	
	cout << res_id;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}