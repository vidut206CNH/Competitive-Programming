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

const int MOD = 998244353;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int f[MAXN2];
int inv[MAXN2];
int rf[MAXN2];
int mod, alpha;
int lf[MAXN2];
int cnt[MAXN2];

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b /= 2;
	}
	
	return res;
}

int C1(int k, int n) {
	return f[n]*power(f[k], MOD - 2)%MOD*power(f[n - k], MOD - 2)%MOD;
}

int C2(int k, int n) {
	int res = 1;
	for(int i = n - k + 1; i <= n; ++i) {
		res = res*i%MOD;
	}
	
	return res*power(f[k], MOD - 2)%MOD;
}

void func(int val, int state) {
	if(val == 1) return;
	int d = lf[val];
	
	while(val%d == 0) {
		cnt[d] += state;
		val /= d;
	}
	
	func(val, state);
}



int C3(int k, int n) {
	memset(cnt, 0, sizeof cnt);
	
	for(int i = n - k + 1; i <= n; ++i) {
		func(i, +1);
	}
	
	for(int i = 2; i <= k; ++i) {
		func(i, -1);
	}
	
	
	int res = 1;
	for(int i = 2; i <= n; ++i) {
		if(cnt[i] == 0) continue;
		res = res*power(i, cnt[i])%mod;
	}
	
	
	return res;
}




signed main() {
	fast_cin();
	
	
/*	freopen("flowers.inp", "r", stdin);
	freopen("flowers.out", "w", stdout);*/
	
	// pre_process
	
	for(int i = 1; i < MAXN2; ++i) lf[i] = i;
	for(int i = 2; i*i < MAXN2; ++i) {
		if(lf[i] != i) continue;
		
		for(int j = i*i; j < MAXN2; j += i) {
			lf[j] = min(lf[j], i);	
		}
		
	}
	
	//
	int t;
	cin >> t >> mod;
	
	if(mod != MOD) {
		while(t--) {
			int n,m,k;
			cin >> n >> m >> k;
			cout << C3(k, n - 1) * m%mod * power(m - 1, k)%mod << "\n";
		}
	}
	
	else {
		f[0] = 1;
		for(int i = 1; i < MAXN2; ++i) f[i] = f[i - 1]*i%mod;
		
		if(t <= 50) {
			while(t--) {
				int m,n,k;
				cin >> n >> m >> k;
				cout << C2(k, n - 1) * m%mod * power(m - 1, k)%mod << "\n";
			}
		}
		
		else {
			while(t--) {
				int m,n,k;
				cin >> n >> m >> k;
				cout << C1(k, n - 1) * m%mod * power(m - 1, k)%mod << "\n";
			}
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}