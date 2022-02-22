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

int n;
int p[2][MAXN1];
int dp[3][MAXN1];
// 0 chon hang 1
// 1 chon hang 2
// 2 khong chon

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < 3; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> p[i][j];
		}
	}
	
	
	for(int j = 1; j <= n; ++j) {
		
		for(int i = 0; i < 3; ++i) {
			if(i == 2) {
				dp[i][j] = max({dp[0][j - 1], dp[1][j - 1], dp[2][j - 1]});
			}
			
			else dp[i][j] = max(dp[i^1][j - 1], dp[2][j - 1]) + p[i][j];
		}
	}
	
	cout << max({dp[0][n], dp[1][n], dp[2][n]});
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}