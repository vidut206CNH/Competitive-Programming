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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e2+5;
const int inf = 1e18;

string s;
int d,n;
int digits[MAXN1];
int dp[MAXN1][MAXN2][2];


int solve(int pos, int rem, bool flag) {
	//flag = true : p[pos] <= digit[pos]
	//flag = false : p[pos] <= 9
	
	if(pos == n + 1) return (rem == 0);
	if(dp[pos][rem][flag] != -1) return dp[pos][rem][flag];
	
	int lim = (flag ? digits[pos] : 9);
	int sum = 0;
	for(int i = 0; i <= lim; ++i) {
		sum = (sum + solve(pos + 1, (rem + i) % d, flag && (i == lim)))%MOD;	
	}
	
	return dp[pos][rem][flag] = sum;
}

signed main() {
	fast_cin();
	
	
	cin >> s >> d;
	n = sz(s);
	for(int i = 0; i < sz(s);++i) {
		digits[i + 1] = s[i] - '0';
	}
	
	memset(dp, -1, sizeof dp);
	
	cout << (solve(0, 0, 1) - 1 + MOD)%MOD;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}