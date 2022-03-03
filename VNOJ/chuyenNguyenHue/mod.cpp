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
const int inf = 1e18;

int x,m,mod;

int mul(int a, int b) {
	int res = 0;
	while(b) {
		if(b&1) res = (res + a)%mod;
		a = (a + a)%mod;
		b /= 2;
	}
	
	return res%mod;
}

int pow(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = mul(res, a)%mod;
		a = mul(a, a)%mod;
		b /= 2;
	}
	return res%mod;
}


int calc(int p, int n) {
	if(n == 0) return 1%mod;
	if(n == 1) return (1 + p)%mod;
	if(n%2) {
		return (1 + mul(p, calc(p, n - 1)))%mod;
	}
	return (mul(1 + pow(p, n/2), calc(p, n/2) - 1 + mod) + 1)%mod;
}


signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		cin >> x >> m >> mod;
		int g = x;
		int cnt = 0;
		while(g) {
			cnt++;
			g /= 10;	
		}
		g = 10;
		int d = pow(g, cnt);

		cout << mul(x%mod, calc(d, m - 1)) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
