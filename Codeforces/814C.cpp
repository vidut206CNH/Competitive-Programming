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
const int MAXN1 = 1505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
char a[MAXN1];
vector< vector<int> > dp(305, vector<int>(MAXN1, inf));

signed main() {
	fast_cin();
	
	cin >> n;
	cin.ignore();
	
	for(int i=1;i<=n;++i) cin >> a[i];
	
	for(int i=1;i<=n;++i) {
		for(int c = (int)'a';c <= (int)'z';++c) {
			int sum = 0;
			for(int j=i;j >= 1;--j) {
				sum += (a[j] != (char)c);
				dp[c][i - j + 1] = min(dp[c][i - j + 1], sum);
			} 
		}
	}
	
/*	for(int c=(int)'a'; c <= (int)'z';++c) {
		for(int i=n;i >= 1; --i) {
			dp[c][i] = min(dp[c][i], dp[c][i+1]);
		}
	}*/
	
	cin >> q;
	for(int i=1;i<=q;++i) {
		int m;
		char c;
		cin >> m >> c;
		int t = upper_bound(dp[c].begin() + 1, dp[c].begin() + n + 1, m) - dp[c].begin() - 1;
		cout << t << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}