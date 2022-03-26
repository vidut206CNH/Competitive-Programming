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
int bit[70];

signed main() {
	fast_cin();
	
	cin >>t ;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n + 5);
		memset(bit, 0, sizeof bit);
		
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			for(int j = 60; j >= 0; --j) {
				bit[j] += (a[i] >> j & 1);
			}
		}
		
		int res = 0;
		for(int i = 1; i <= n; ++i) {
			int val = a[i];
			int sum1 = 0;
			int sum2 = 0;
			for(int c = 0; c <= 60; ++c) {
				if(val >> c & 1) {
					sum1 = (sum1 + (1LL << c)%MOD*n%MOD)%MOD;
				}
				else {
					sum1 = (sum1 + (1LL << c)%MOD*bit[c]%MOD)%MOD;
				}	
			}
			
			for(int c = 0; c <= 60; ++c) {
				if(val >> c & 1) {
					sum2 = (sum2 + (1LL << c)%MOD*bit[c]%MOD)%MOD;
				}
			}
			
			res = (res + sum1*sum2%MOD)%MOD;
		}
		
		cout << res << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}