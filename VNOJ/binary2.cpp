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

const int MOD = 1e9;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int f[MAXN2];


signed main() {
	fast_cin();
	
	cin >> n >> k;
	f[0] = f[1] = 2;
	
	for(int i = 2; i <= k; ++i) {
		f[i] = 2*f[i - 1]%MOD;
	}
	
	for(int i = k + 1; i <= n; ++i) {
		f[i] = (2*f[i - 1] - f[i - k - 1] + MOD*MOD)%MOD;
	}
	
	cout << f[n]%MOD;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
