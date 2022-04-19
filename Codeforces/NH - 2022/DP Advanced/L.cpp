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
const int MAXN1 = 5005;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

int n,k,s;
int a[MAXN1];
int p[MAXN1][MAXN1];
int dp[MAXN1][MAXN1];
int mindp[MAXN1][MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k >> s;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for(int i = 1; i <= k; ++i) {
		int j = i;
		while(j <= n) {
			p[i][a[j]]++;
			j += k;
		}
	}
	
	// DP
	memset(dp, 0x3f, sizeof dp);
	memset(mindp, 0x3f, sizeof mindp);
	dp[0][0] = 0;
	
	for(int w = 0; w <= s; ++w) {
		mindp[0][w] = 0;
	}
	
	for(int i = 1; i <= k; ++i) {
		for(int w = 0; w <= s; ++w) {
			int j = i;
			int cnt = (n - i)/k + 1;
			while(j <= n) {
				if(w >= a[j]) dp[i][w] = min(dp[i][w], dp[i - 1][w - a[j]] + (cnt - p[i][a[j]]));
				j += k;
			}
			dp[i][w] = min(dp[i][w], mindp[i - 1][w] + cnt);
/*			db(i);
			db(w);
			db(dp[i][w]);
			cerr << "\n";*/
			mindp[i][w] = (w == 0 ? dp[i][w] : min(mindp[i][w - 1], dp[i][w]));
		}
	}
	
	cout << dp[k][s];
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}