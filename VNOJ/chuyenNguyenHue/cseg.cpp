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
const int MAXN1 = 4e4;
const int MAXN2 = 8e4 + 5;
const int inf = 1e18;

int t;
int a[205];
int dp[MAXN2];


signed main() {
	fast_cin();
	
	cin >> t;

		
	
	while(t--) {
		int n,x;
		cin >> n >> x;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] -= x;
		}
		memset(dp, 0, sizeof dp);
		dp[MAXN1] = 1;
		
		for(int i = 1; i <= n; ++i) {
			if(a[i] < 0) {
				for(int val =  0; val < MAXN2 + a[i]; ++val) {
					dp[val] = (dp[val] + dp[val - a[i]])%MOD;
				}
			} else {
				for(int val = MAXN2 - 1; val >= a[i]; --val) {
					dp[val] = (dp[val] + dp[val - a[i]])%MOD;
				}
			}
		}
		
		cout << dp[MAXN1] - 1 << "\n";
		
	}
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}