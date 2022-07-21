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
const long long inf = 5e18;

int n,m;
int A,B;
int a[MAXN1];
long long st[4*MAXN1];
long long dp[4*MAXN1];
long long f[MAXN1];
long long lazy[4*MAXN1];
long long spec[4*MAXN1];

void down(int id, int l, int r) {
	st[id] += lazy[id];
	
	if(l != r) {
		lazy[id << 1] += lazy[id];
		lazy[id << 1|1] += lazy[id];
	}
	
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, long long val) {
	down(id, l, r);
	if(u <= l && r <= v) {
		lazy[id] += val;
		down(id, l, r);
		return;
	}
	
	int mid = (l + r) >> 1;
	if(u <= mid) update(id << 1, l, mid, u, v, val);
	if(mid + 1 <= v) update(id << 1|1, mid + 1, r, u, v, val);
	
	st[id] = min(st[id << 1], st[id << 1|1]);
}


long long get(int id, int l, int r, int u, int v) {
	if(u > v) return inf;
	down(id, l, r);
	if(u <= l && r <= v) return st[id];
	
	int mid = (l + r) >> 1;
	long long res = inf;
	if(u <= mid) res = min(res, get(id << 1, l, mid, u, v));
	if(mid + 1 <= v) res = min(res, get(id << 1|1, mid + 1, r, u, v));
	return res;
}

int main() {
	fast_cin();
	
/*	freopen("candy.inp", "r", stdin);
	freopen("candy.out", "w", stdout);*/
	
	cin >> n >> m;
	cin >> A >> B;
	
	for(int i = 1; i <= n; ++i) cin >> a[i];	
	for(int i = 1; i <= n; ++i) f[i] = f[i - 1] + a[i];
	
	//for(int i = 1; i < 4*MAXN1; ++i) st[i] = inf;
	
	spec[n + 1] = 1LL*A*f[n];
	int pos = n;
	for(int i = n; i >= 1; --i) {
		while(f[pos] - f[i - 1] > m) pos--;
		++pos;
		pos = min(pos, n);
/*		db(pos);
		cerr << "\n";*/
		
		dp[i] = inf;
		
		if(f[pos] - f[i - 1] <= m) {
			dp[i] = 1LL*B*m - 1LL*B*(f[pos] - f[i - 1]);
		}
		
		else {
			long long val1 = spec[pos + 1] + 1LL*A*(- f[i - 1] - m);
			dp[i] = min(dp[i], val1);
			
			
			long long val2 = get(1, 1, n, i + 1, pos) + 1LL*B*m - 1LL*a[i]*B;
			dp[i] = min(dp[i], val2);	
		}
		
		
		update(1, 1, n, i + 1, n, -1LL*a[i]*B);
		update(1, 1, n, i, i,dp[i]);
		spec[i] = min(spec[i + 1], dp[i] + 1LL*A*f[i - 1]);
	}
	
	cout << dp[1];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}