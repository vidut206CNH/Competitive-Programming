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
int dp[15][155][155][2][2];
vector<int> digits;
int mod = 0;

int solve(int pos, int rem,int rsum, bool equal,bool positive) {
	if(pos == sz(digits)) {
		if(rem == 0 && positive && rsum == 0) return 1;
		else return 0;
	}
	
	if(dp[pos][rem][rsum][equal][positive] != -1) return dp[pos][rem][rsum][equal][positive];
	
	int res = 0;
	
	for(int next = 0; next <= 9; ++next) {
		if(next > digits[pos] && equal) break;
		if(rsum - next < 0) break;
		bool equal2 = (equal && next == digits[pos]);
		bool positive2 = (positive || next > 0);
		int rem2 = (rem*10 + next)%mod;
		int rsum2 = rsum - next;
		res += solve(pos + 1, rem2, rsum2, equal2, positive2);
	}
	
	return dp[pos][rem][rsum][equal][positive] = res;
}


signed main() {
	fast_cin();
	
	cin >> n;
	int g = n;
	while(g) {
		digits.push_back(g%10);
		g /= 10;
	}
	
	reverse(digits.begin(), digits.end());
	
	int res = 0;
	
	for(int val = 1; val <= 9*12; ++val) {
		memset(dp, -1, sizeof dp);
		mod = val;
		res += solve(0, 0, val, 1, 0);
	}	
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}