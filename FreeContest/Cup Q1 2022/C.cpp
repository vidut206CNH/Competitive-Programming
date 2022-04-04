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
const int MAXN2 = 2e6+10;
const int inf = 1e18;


int t;
int f[MAXN2];

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	
	return res;
}

int C(int g, int k) {
	return f[g]*power(f[k], MOD - 2)%MOD*power(f[g - k], MOD - 2)%MOD;
}


int solve(int n) {
	return f[n]*C(2*n, n)%MOD*f[n]%MOD*power(power(2, n)%MOD, MOD - 2)%MOD;
}

signed main() {
	fast_cin();
	
	cin >> t;
	f[0] = 1;
	for(int i = 1; i < MAXN2; ++i) f[i] = f[i - 1]*i%MOD;
	
	
	while(t--) {
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}