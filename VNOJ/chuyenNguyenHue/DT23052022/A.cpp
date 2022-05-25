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

int a,b,x,y;
int f[MAXN1];

int power(int A, int B) {
	int C = 1;
	while(B) {
		if(B&1) C = C*A%MOD;
		A = A*A%MOD;
		B /= 2;
	}
	
	return C;
}

int C(int k, int n) {
	if(k > n) return 0;
	if(k < 0) return 0;
	return f[n]*power(f[k], MOD - 2)%MOD*power(f[n - k], MOD - 2)%MOD;
}

signed main() {
	fast_cin();
	
	f[0] = 1;
	for(int i = 1; i < MAXN1; ++i) f[i] = f[i - 1]*i%MOD;
	cin >> a >> b >> x >> y;
	
	int res = 0;
	for(int val = 0; val <= min(x, a); ++val) {
		if(abs(2*val - x) <= y) res = (res + C(val, a)*C(x - val, b)%MOD)%MOD;
	}
	
	cout << res << "\n";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}