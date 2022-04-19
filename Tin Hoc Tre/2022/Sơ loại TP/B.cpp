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
const int MAXN1 = 1e3+3;
const int MAXN2 = 303;
const long long inf = 1e18;

int m,n,k;
long long t;
long long prefix[MAXN1][MAXN1];
long long dp[MAXN2][MAXN2][MAXN2];
int a[MAXN1][MAXN1];


void solve1() {
	
	int low = 1, high = min(m,n);
	long long res = 0;
	while(low <= high) {
		int mid = (low + high) >> 1;
		bool can = false;
		//db(mid);
		//cerr << "\n";
		for(int i = mid; i <= m; ++i) {
			for(int j = mid; j <= n; ++j) {
				long long sum = prefix[i][j] - prefix[i - mid][j] - prefix[i][j - mid] + prefix[i - mid][j - mid];
				//db(sum);
				can |= (sum <= t);
				
			}
		}
		//cerr << '\n';
		if(can) {
			res = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	
	cout << res*res;
	
}

int find_best(int x, int y, long long sum) {
	int low = 1, high = min(x, y), res = -1;
	
	while(low <= high) {
		int mid = (low + high) >> 1;
		if(dp[x][y][mid] <= sum) {
			res = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	
	return res;
}

void solve2() {
	
	// memset
	for(int len = 0; len <= min(m,n); ++len) {
		for(int i = 0; i <= m; ++i) {
			for(int j = 0; j <= n; ++j) {
				dp[i][j][len] = inf;
			}
		}
	}
	
	
	for(int len = 1; len <= min(m,n); ++len) {
		for(int i = len; i <= m; ++i) {
			for(int j = len; j <= n; ++j) {
				dp[i][j][len] = min(dp[i - 1][j][len], dp[i][j - 1][len]);
				
				long long sum = prefix[i][j] - prefix[i - len][j] - prefix[i][j  - len] + prefix[i - len][j - len];
				dp[i][j][len] = min(dp[i][j][len], sum);
							
			}
		}
	}
	
	int res = 0;
	
	for(int len = 1; len <= min(m,n); ++len) {
		int best = -1;
		
		for(int i = len; i <= m; ++i) {
			for(int j = len; j <= n; ++j) {
				long long sum = prefix[i][j] - prefix[i - len][j] - prefix[i][j - len] + prefix[i - len][j - len];
				
				if(sum > t) break;
				
				int best1 = upper_bound(dp[i - len][j] + 1, dp[i - len][j] + min(i - len, j) + 1, t - sum) - dp[i - len][j] - 1;
				int best2 = upper_bound(dp[i][j - len] + 1, dp[i][j - len] + min(i, j - len) + 1, t - sum) - dp[i][j - len] - 1;
				
				best = max({best, best1, best2});
			}
		}
		
		if(best != -1) res = max(res, len*len + best*best);
		
	}
	
	cout << res;
}


signed main() {
	fast_cin();
	
	
	cin >> m >> n >> k >> t;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j]  - prefix[i - 1][j - 1] + a[i][j];
		}
	}
	
	if(k == 1) {
		solve1();
	}
	
	else solve2();
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}