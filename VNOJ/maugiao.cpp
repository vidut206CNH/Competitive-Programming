/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int n;
long long dp[21][(1 << 20) + 5];
long long cnt[21][(1 << 20) + 5];
long long cost[21][21];

int main() {
	fast_cin();
	
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> cost[i][j];
		}
	}
	
	for(int j = 0; j < n; ++j) {
		dp[0][1 << j] = cost[0][j];
		cnt[0][1 << j] = 1;
	}
	
	for(int i = 0; i < n; ++i) {
		for(int cur = 0; cur < (1 << n); ++cur) {
			if(__builtin_popcount(cur) != i + 1) continue;
			
			long long val = dp[i][cur];
			long long val1 = cnt[i][cur];
			for(int j = 0; j < n; ++j) {
				if(!(cur >> j & 1)) {
					if(dp[i + 1][cur | (1 << j)] < val + cost[i + 1][j]) {
						dp[i + 1][cur | (1 << j)] = val + cost[i + 1][j];
						cnt[i + 1][cur | (1 << j)] = 0;
					}
					
					if(dp[i + 1][cur | (1 << j)] == val + cost[i + 1][j]) {
						cnt[i + 1][cur | (1 << j)] += val1; 
					}
				}
			}		
		}
	}
	
	cout << dp[n - 1][(1 << n) - 1] << " " << cnt[n - 1][(1 << n) - 1];
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}