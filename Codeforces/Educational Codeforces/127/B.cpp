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
int a[MAXN1];
bool dp[3][MAXN1];

int f(int val) {
	if(val == 0) return -1;
	if(val == 1) return 0;
	return +1;
}

signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		
		for(int i = 0; i < 3; ++i) {
			dp[i][1] = true;
			dp[i][1] = true;
			dp[i][1] = true;
			for(int pos = 2; pos <= n; ++pos) dp[i][pos] = false;
		}
		
		for(int pos = 2; pos <= n; ++pos) {
			for(int i = 0; i < 3; ++i) {
				int val = a[pos] + f(i);
				
				for(int j = 0; j < 3; ++j) {
					dp[i][pos] |= ((a[pos - 1] + f(j) == val - 1) && dp[j][pos - 1]);
				}
				
			}
		}
		
		int res = false;
		for(int i = 0 ; i < 3; ++i) {
			res |= (dp[i][n]);
		}
		
		cout << (res ? "YES\n" : "NO\n");
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}