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
const int MAXN1 = 3005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

struct data{
	int A, B, C;
};

int n;
int dp[MAXN1][MAXN1][2];
// dp(pos, cntc, cnta)


void mini(int &res, int val) {
	if(res > val) res = val;
}

data a[MAXN1];


signed main() {
	fast_cin();

	cin >> n;	
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].A >> a[i].B >> a[i].C;
	}
	
	sort(a + 1, a + n + 1, [&](const data &X, const data &Y) {
		return X.B - X.A < Y.B - Y.A;
	});
	
	
	for(int i = 0; i <= n; ++i) {
		for(int j = 0;j <= n; ++j) {
			for(int c = 0; c < 2; ++c) {
				dp[i][j][c] = inf;
			}
		}
	}
	
	dp[0][0][0] = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int cntc = 0; cntc <= i; cntc++) {
			for(int cnta = 0; cnta < 2; ++cnta) {
				int cur = dp[i][cntc][cnta];
				if(cur == inf) continue;
/*				db(cur);
				db(i);
				db(cntc);
				db(cnta);
				cerr << "\n";*/
				mini(dp[i + 1][cntc + 1][cnta], cur + a[i + 1].C - cntc);
				
				if(cnta == 0) {
					mini(dp[i + 1][cntc][!cnta], cur + a[i + 1].A);
					mini(dp[i + 1][cntc][cnta], cur - (i - cntc) + a[i + 1].B);
				} else {
					mini(dp[i + 1][cntc][cnta], cur + a[i + 1].A);
				}
			}
		}
	}
	int res = inf;
	for(int cntc = 0; cntc <= n; ++cntc) {
		for(int cnta = 0; cnta < 2; ++cnta) {
			res = min(res, dp[n][cntc][cnta]);
		}
	}
	
	cout << res;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}