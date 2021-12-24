/*
	Author : vidut_206_CNH
	Link problem: 
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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "


typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int f[20][MAXN1];



signed main() {
	fast_cin();
	int t;
	
	for(int i=1;i<MAXN1;++i) {
		for(int mask=0;(1 << mask) < MAXN1;++mask) {
			f[mask][i] = f[mask][i-1];
			if((i >> mask) & 1) {
				f[mask][i]++;
			}
		}
	}
	
	cin >> t;
	while(t--) {
		int l;
		int r;
		cin >> l >> r;
		int res = 0;
		for(int i=0;(1 << i) <= r;++i) {
			res = max(res, f[i][r] - f[i][l-1]);
		}
		cout << r - l + 1 - res << "\n";
	}
	
	
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock_t() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
