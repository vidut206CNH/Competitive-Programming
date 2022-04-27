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

int q;
int dp[MAXN2][15];
int f[MAXN2];

signed main() {
	fast_cin();
	
	
	for(int i = 1; i <= 9; ++i) {
		f[i] = i;
		dp[i][i] = 1;
		for(int k = 1; k <= 9; ++k) {
			dp[i][k] += dp[i - 1][k];
		}
	}
	
	for(int i = 10; i <= (int)(1e6); ++i) {
		int val = i;
		vector<int> digit;
		while(val) {
			if(val%10) digit.push_back(val%10);
			val /= 10;
		}
		int mul = 1;
		for(auto x : digit) {
			mul *= x;
		}
		
		f[i] = f[mul];
		dp[i][f[i]] = 1;
		for(int k = 1; k <= 9; ++k) {
			dp[i][k] += dp[i - 1][k];
		}
	}
	
	cin >> q;
	
	while(q--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << dp[r][k] - dp[l - 1][k] << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}