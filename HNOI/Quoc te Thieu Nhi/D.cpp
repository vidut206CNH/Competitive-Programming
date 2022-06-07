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
const int MAXN1 = 5e5+3;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int f[MAXN1];
int dp[MAXN1];
int st[2][3*MAXN1];
int g[MAXN1];
vector<int> vals;

void build(int type, int id, int l, int r) {
	if(l == r) {
		st[type][id] = -inf;
		return;
	}
	
	int mid = (l + r) >> 1;
	build(type, id << 1, l, mid);
	build(type, id << 1|1, mid + 1, r);
	st[type][id] = max(st[type][id << 1], st[type][id << 1|1]);
}


void update(int type, int id, int l, int r, int &X, int val) {
	if(X < vals[l] || X > vals[r]) return;
	
	if(l == r) {
		st[type][id] = max(st[type][id], val);
		return;
	}
	int mid = (l + r) >> 1;
	
	update(type, id << 1, l, mid, X, val);
	update(type, id << 1|1, mid + 1, r, X, val);
	st[type][id] = max(st[type][id << 1], st[type][id << 1|1]);
}

int get(int type, int id, int l, int r, int U, int V) {
	if(V < vals[l] || vals[r] < U) return -inf;
	
	if(U <= vals[l] && vals[r] <= V) {
		return st[type][id];
	}
	
	int mid = (l + r) >> 1;
	return max(get(type, id << 1, l, mid, U, V), get(type, id << 1|1, mid + 1, r, U, V)); 
}

signed main() {
	fast_cin();
	
	cin >> n;
	vals.push_back(0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
		vals.push_back(f[i]);
	}
	
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	
	build(0, 1, 0, sz(vals) - 1);
	build(1, 1, 0, sz(vals) - 1);
	for(int i = 0; i < sz(vals); ++i) g[i] = -inf;
	
	for(int i = 0; i <= n; ++i) {
		
		dp[i] = (i == 0 ? 0 : -inf);
		int val1 = get(0, 1, 0, sz(vals) - 1, -inf, f[i] - 1);
		int val2 = get(1, 1, 0, sz(vals) - 1, f[i] + 1, inf);
		int val3 = g[lower_bound(vals.begin(), vals.end(), f[i]) - vals.begin()];
		
		if(val1 != inf) dp[i] = max(dp[i], val1 + i);
		if(val2 != inf) dp[i] = max(dp[i], val2 - i);
		if(val3 != inf) dp[i] = max(dp[i], val3);
		
		update(0, 1, 0, sz(vals) - 1, f[i], dp[i] - i);
		update(1, 1, 0, sz(vals) - 1, f[i], dp[i] + i);
		g[lower_bound(vals.begin(), vals.end(), f[i]) - vals.begin()] = dp[i];
	}
	
	cout << dp[n];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
