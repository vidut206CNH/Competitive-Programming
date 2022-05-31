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

const long long MOD = 998244353;
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;

long long power(long long a, long long b) {
	long long res = 1;
	while(b) {
		if(b&1) res = 1LL*res*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	
	return res;
}

int n,k;
long long f[MAXN1];


long long C(int x, int y) {
	return f[y]*power(f[x], MOD - 2)%MOD*power(f[y - x], MOD - 2)%MOD;
}


int main() {
	fast_cin();
	
	f[0] = 1;
	for(int i = 1; i < MAXN1; ++i) f[i] = f[i - 1]*i%MOD;
	
	cin >> n >> k;
	
	long long res = 0;
	
	for(int red = 0; red <= k; ++red) {
		int blue = k - red;
		if(red >= blue - red) {
			db(red);
			res = (res + f[k]*power(f[red], MOD - 2)%MOD*power(f[blue], MOD - 2)%MOD)%MOD;
			db(res);
		}
	}
	
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}