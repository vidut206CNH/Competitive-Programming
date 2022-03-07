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

int t;
int f[20];
map<int,int> dp;


int calc(int val, int lim) {
	if(val == 0) return 0;
	int res = __builtin_popcountll(val);
	for(int i = 3; i <= 15; ++i) {
		if(f[i] > lim) break;
		res = min(res, 1 + calc(val - f[i], min(f[i] - 1, f[i])));
	}
	
	return res;
}

signed main() {
	fast_cin();
	f[0] = 1;
	for(int i = 1; i <= 15; ++i) f[i] = f[i - 1]*i;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		dp.clear();
		cout << calc(n, n) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}