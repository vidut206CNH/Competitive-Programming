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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 998244353;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int dp[MAXN1];
int f[MAXN1];
int n;

// modular inverse 
int inv(int A,int B) {
	return (1 < A ? B - inv(B%A, A)*B/A : 1);	
}

signed main() {
	fast_cin();
	
	cin >> n;
	dp[1] = 1;
	f[1] = 1;
	for(int i=2;i<=n;++i) {
		f[i] = dp[i-1];
		if(i%2) f[i] = (f[i] + 1)%MOD;
		dp[i] = (f[i] + dp[i-2])%MOD;
	}	
	int res = 1, b = n, base = 2;
	while(b) {
		if(b&1) res = res*base%MOD;
		base = base*base%MOD;
		b /= 2;
	}
	
	cout << f[n]*inv(res, MOD)%MOD << "\n";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}