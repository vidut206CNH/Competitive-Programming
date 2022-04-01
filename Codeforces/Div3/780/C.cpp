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
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t,n;
int dp[3][MAXN1];
int last[35];


signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		string a;
		cin >> a;
		n = sz(a);
		a = '0' + a;
		memset(last, -1, sizeof last);
		for(int i = 0; i <= n; ++i) {
			for(int k = 0; k < 3; ++k) {
				dp[k][i] = inf;
			}
		}
		
		dp[0][0] = 0;
		
		for(int i = 1; i <= n; ++i) {
			for(int k = 0; k < 3; ++k) {
				if(k == 0) {
					dp[k][i] = min({dp[0][i - 1], dp[2][i - 1]}) + 1;
				}
				
				if(k == 1) {
					dp[k][i] = min(dp[0][i - 1], dp[2][i - 1]);
				}
				
				if(k == 2 && last[a[i] - 'a'] != -1) {
					int l = last[a[i] - 'a'];
					dp[k][i] = dp[1][l] + i - l - 1;
				}
			}
			
			last[a[i] - 'a'] = i;
		}
		
		
		cout << min(dp[0][n], dp[2][n]) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}