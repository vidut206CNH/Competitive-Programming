/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
/// const  inf = 1e18;

int n;
int h[MAXN1];

int dp[MAXN1];
// signed = int = signed int





int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> h[i];
	
	
	memset(dp, 0, sizeof dp);
	cout << dp[0];
	dp[1] = 0;
	for(int i = 1; i <= n; ++i) {
		int i1 = i + 1;
		int i2 = i + 2;
		 
		dp[i1] = ((dp[i1] == -1) ? dp[i] + abs(h[i1] - h[i]) : min(dp[i1], dp[i] + abs(h[i1] - h[i])));
		dp[i2] = ((dp[i2] == -1) ? dp[i] + abs(h[i2] - h[i]) : min(dp[i2], dp[i] + abs(h[i2] - h[i])));
	}
	
	//cout << dp[n];
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}