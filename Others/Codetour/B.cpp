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

const long long MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int n;
long long a[MAXN1];
long long f[MAXN1];
long long g[MAXN1];


long long power(long long A, long long B) {
	long long res = 1;
	while(B) {
		if(B&1) res = res*A%MOD;
		A = A*A%MOD;
		B /= 2;
	}
	
	return res;
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = (f[i - 1] + a[i])%MOD;
		g[i] = (g[i - 1] + a[i]*a[i])%MOD;
	}
	
	long long res = 0;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; j += i) {
			long long sum = (f[j] - f[j - i]);
			sum = sum*sum%MOD;
			sum = (sum - (g[j] - g[j - i]) + MOD*MOD)%MOD;
			res = (res + sum)%MOD;
		}
		
		if(n%i) {
			long long sum = f[n] - f[n/i*i];
			sum = sum*sum%MOD;
			sum = (sum - (g[n] - g[n/i*i]) + MOD*MOD)%MOD;
			res = (res + sum)%MOD;
		}
			
	}
	
	cout << res*power(2, MOD - 2)%MOD;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}