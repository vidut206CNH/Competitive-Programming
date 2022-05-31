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
const int MAXN1 = 2e5+5;
const int MAXN2 = 2e6+5;
const int inf = 1e18;

int n, len = 0;
int val[MAXN1];
int cnt[MAXN1];
int f[2*MAXN2];


int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	
	return res;
}


signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> val[i] >> cnt[i];
		len += cnt[i];
	}
	
	f[0] = 1;
	
	for(int i = 1; i < 2*MAXN2; ++i) {
		f[i] = f[i - 1]*i%MOD;
	}
	
	if(n == 1) {
		int res = val[1];
		for(int i = 1; i <= cnt[1]; ++i) {
			res = res * i%MOD;
		}
		
		cout << res;
		exit(0);
	}	
	
	if(n == 2 && cnt[1] == cnt[2]) {
		int g = f[len]*power(f[len/2], MOD - 2)%MOD*power(f[len/2 + 1], MOD - 2)%MOD*f[len/2]%MOD*f[len/2]%MOD;
		//db(g);
		int d = (f[len] - g + MOD*MOD)%MOD;
		//db(d);
		cout << ((g*val[1]%MOD + d*val[2]%MOD)%MOD);
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}