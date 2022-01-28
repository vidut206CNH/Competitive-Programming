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
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int dp[MAXN1];
int trace[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	
	dp[1] = 1;
	trace[1] = 1;
	for(int val = 2; val <= n; ++val) {
		dp[val] = 1;
		trace[val] = 1;
		for(int i=2;i*i <= val;++i) {
			if(val%i) continue;
			if(dp[(i - 1)*(val/i + 1)] + 1 > dp[val]) {
				dp[val] = dp[(i - 1)*(val/ i + 1)] + 1;
				trace[val] = i;
			}
		}
/*		db(dp[val]);
		db(trace[val]);
		cerr << "\n";*/
	}
	
	int m = n;
	vector<pii > res;
	while(dp[m]) {
		res.push_back({trace[m], m/trace[m]});
		m = (trace[m] - 1)*(m/trace[m] + 1);
/*		db(m);
		cerr << "\n";*/
		
	}
	
	cout << sz(res) << "\n";
	for(auto x : res) cout << x.fi << " " << x.se << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}