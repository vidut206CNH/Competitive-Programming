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

int a[MAXN1];
int b[MAXN1];
vector<int> p(4);
int dp[20];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(i == 1) p[0] = a[i];
			if(i == n) p[1] = a[i];
		}
		for(int i = 1; i <= n; ++i) {
			cin >> b[i];
			if(i == 1) p[2] = b[i];
			if(i == n) p[3] = b[i];
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		
		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0;
		for(int mask = 0; mask < (1 << 4); ++mask) {
			for(int i = 0; i < 2; ++i) {
				int pos = lower_bound(b + 1, b + n + 1, p[i]) - b;
				int minn = inf;
				if(pos != 1) minn = min(minn, abs(p[i] - b[pos - 1]));
				if(pos != n + 1) minn = min(minn, abs(p[i] - b[pos]));
				dp[mask|(1 << i)] = min(dp[mask | (1 << i)], dp[mask] + minn);		
			
				int mask1 =(mask|(1 << i));
				for(int j = 2; j < 4; ++j) {
					dp[mask1 | (1 << j)] = min(dp[mask1|(1 << j)], dp[mask] + abs(p[i] - p[j]));
				}
			}
			
			for(int i = 2; i < 4; ++i) {
				int pos = lower_bound(a + 1, a + n + 1, p[i]) - a;
				int minn = inf;
				if(pos != 1) minn = min(minn, abs(p[i] - a[pos - 1]));
				if(pos != n + 1) minn = min(minn, abs(p[i] - a[pos]));
				dp[mask|(1 << i)] = min(dp[mask | (1 << i)], dp[mask] + minn);		
			
				int mask1 =(mask|(1 << i));
				
				for(int j = 0; j < 2; ++j) {
					dp[mask1 | (1 << j)] = min(dp[mask1|(1 << j)], dp[mask] + abs(p[i] - p[j]));
				}
			}
/*			db(dp[mask]);
			db(mask);
			cerr << '\n';*/
		}
		
		
		cout << dp[(1 << 4) - 1] << "\n";
	}	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}