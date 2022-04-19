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
int dp[2005];
int a[MAXN1];


signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	
	dp[0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int val = 0; val <= 1000; ++val) {
			if(dp[val] == -1 || dp[val] >= a[i]) continue;
			int val1 = val^a[i];
			if(dp[val1] == -1 || dp[val1] > a[i]) {
				dp[val1] = a[i];
/*				db(val1);
				db(a[i]);
				cerr << "\n";*/
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i <= 1000; ++i) {
		if(dp[i] != -1) ans.push_back(i);
	}
	
	cout << sz(ans) << "\n";
	for(auto x : ans) cout << x << " ";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}