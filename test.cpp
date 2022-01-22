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
const int MAXN1 = 1 << 20;
const int MAXN2 = 1e6+5;
const int inf = 1e15;

int n;
int a[25];
vector< vector<int> > dp(2, vector<int>(MAXN1));


signed main() {
	fast_cin();
	
	
	cin >> n;
	
	for(int i=0;i<n;++i) cin >> a[i];
	dp[0].assign(MAXN1, inf);
	dp[1].assign(MAXN1, -inf);
	dp[0][0] = 0;
	dp[1][0] = 0;
	int lim = 1 << n;
	
	for(int state = 1;state < lim;++state) {
		if(__builtin_popcountll(state)%2) continue;
		
		for(int i=0;i<n;++i) {
			if(!(state >> i & 1)) continue;
			for(int j=i+1;j<n;++j) {
				if(!(state >> j & 1)) continue;
				int cur = ((state&(~(1 << i)))&(~(1 << j)));
				dp[0][state] = min(dp[0][cur] + (a[i]^a[j]), dp[0][state]);
/*				db(dp[0][state]);
				db(state);
				cerr << "\n";*/
				dp[1][state] = max(dp[1][cur] + (a[i]^a[j]), dp[1][state]);
			}
		}
		
	} 
	
	cout << dp[0][lim - 1] << " " << dp[1][lim - 1];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}