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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
// int inf = 1e18;

string s;
char a[6][MAXN2];
int dp[5][5][MAXN2];

signed main() {
	fast_cin();
	
	freopen("removepalin.inp", "r", stdin);
	freopen("removepalin.out", "w", stdout);
	
	cin >> s;
	int n = sz(s);
	s = '0' + s;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 5; ++j) {
			a[j][i] = s[i] + j - 2;
			if(a[j][i] < 'a') a[j][i] += 26;
			if(a[j][i] > 'z') a[j][i] -= 26;
		}
	}
	
	if(n == 1) {
		cout << 0;
		return 0;
	}
	
	
	// DP
	memset(dp, 0x3f, sizeof dp);
	
	
	int res = MOD;
	
	for(int cur = 0; cur < 5; ++cur) {
		for(int pre = 0; pre < 5; ++pre) {
			if(a[cur][2] == a[pre][1]) continue;
			
			dp[cur][pre][2] = abs(cur - 2) + abs(pre - 2);
			
			if(n == 2) res = min(res, dp[cur][pre][2]);
			
		}
	}	
	
	for(int pos = 2; pos < n; ++pos) {
		for(int cur = 0; cur < 5; ++cur) {
			for(int pre = 0; pre < 5; ++pre) {
				if(a[cur][pos] == a[pre][pos - 1]) continue;
				
				int val = dp[cur][pre][pos];
				
				for(int next = 0; next < 5; ++next) {
					if(a[next][pos + 1] == a[cur][pos] || a[next][pos + 1] == a[pre][pos - 1]) continue;
					dp[next][cur][pos + 1] = min(dp[next][cur][pos + 1], val + abs(next - 2));
				}
			}
		} 
	}
	
	
	for(int cur = 0; cur < 5; ++cur) {
		for(int pre = 0; pre < 5; ++pre) {
			res = min(res, dp[cur][pre][n]);
		}
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}