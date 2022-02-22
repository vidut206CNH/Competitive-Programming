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
<<<<<<< HEAD
const int MAXN1 = 205;
const int MAXN2 = 2e4+5;
const int inf = 1e18;

int t;
int a[MAXN1];
unordered_map<int,int> dp[2];
=======
const int MAXN1 = 4e4;
const int MAXN2 = 8e4 + 5;
const int inf = 1e18;

int t;
int a[205];
int dp[MAXN2];

>>>>>>> 85009bc1c3d0301dee28c2fb8a965ade8f8b431d

signed main() {
	fast_cin();
	
	cin >> t;
<<<<<<< HEAD
	while(t--) {
		int n,X;
		cin >> n >> X;
		
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] -= X;
		}
		dp[0].clear();
		dp[1].clear();
		dp[0][0] = 1;
		for(int i = 0; i < n; ++i) {	
			for(auto x : dp[i%2]) {
				
				int cur = x.fi;
				int val = x.se;
				
				dp[!(i%2)][cur] = (dp[!(i%2)][cur] + val)%MOD;
				dp[!(i%2)][cur + a[i + 1]] = (dp[!(i%2)][cur + a[i + 1]] + val)%MOD;
			}
			dp[i%2].clear();
		}
		cout << dp[n%2][0] - 1 << "\n";
	}
	
	
=======
		
	
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
>>>>>>> 85009bc1c3d0301dee28c2fb8a965ade8f8b431d
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}