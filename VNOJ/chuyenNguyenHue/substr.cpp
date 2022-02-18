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
string s;
int dp[5003][5003];

signed main() {
	fast_cin();
	
	getline(cin , s);
	n = sz(s);
	int res1 = 0,res2 = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i; j >= 0; --j) {
			if(i == j) dp[j][i] = 1;
			else {
				if(s[i] == s[j]) {
					dp[j][i] = dp[j + 1][i - 1] + 2;
				} else {
					dp[j][i] = max(dp[j][i - 1], dp[j + 1][i]);
				}
			}
			
			res1 = max(res1, dp[j][i]);
		}
	}
	
	memset(dp, false, sizeof dp);
	
	for(int i = 0; i < n; ++i) {
		for(int j = i;  j >= 0; --j) {
/*			db(i);
			db(j);*/
			if(i == j) dp[j][i] = 1;
			
			else {
				if(s[i] == s[j] && (j + 1 == i || dp[j + 1][i - 1])) {
					dp[j][i] = 1;
				}
			}
			
			if(dp[j][i]) res2 = max(res2, i - j + 1);
/*			db(dp[j][i]);
			cerr << "\n";*/
		}
	}
	
	
	cout << res2 << "\n" << res1;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}