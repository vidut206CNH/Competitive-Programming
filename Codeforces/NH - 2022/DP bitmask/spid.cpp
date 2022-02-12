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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int dp[2][MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	
	

	
	memset(dp, -1, sizeof dp);
	for(int val = 1; val <= 100; ++val) dp[1][val] = abs(a[1] - val);
		
	for(int pos = 2; pos <= n; ++pos) {
		bool t = pos&1;
		bool u = !t;
/*		db(u);
		db(t);
		cerr << "\n";*/
		memset(dp[t], 0x3f, sizeof dp[t]);
		
		for(int pre = 1; pre <= 100; ++pre) {
			for(int cur = pre + 1; cur <= 100; ++cur) {
				dp[t][cur] = min(dp[t][cur], dp[u][pre] + abs(a[pos] - cur));
/*				db(dp[t][cur]);
				db(dp[u][pre]);
				cerr << "\n";*/
			}
		}
	}
	
	int res = 1e9;
	for(int i = 1; i <= 100; ++i) res = min(dp[n&1][i], res);
	
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}