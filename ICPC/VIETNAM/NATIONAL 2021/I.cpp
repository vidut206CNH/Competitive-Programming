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
const int N = 53;
const int M = 16;
const int inf = 1e18;


int dp[N][M][M][M][M][M];
vector<string> a[N];
pii g[10];
int n;

int fi(string x) {
	if(x == "dp") return 1;
	if(x == "graph") return 2;
	if(x == "mathgeo") return 3;
	if(x == "ds") return 4;
	if(x == "adhoc") return 5;
	return 0;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		for(int j = 1; j <= t; ++j) {
			string s;
			cin >> s;
			a[i].push_back(s);
		}
	}
	
	for(int i = 1; i <= 5; ++i) {
		cin >> g[i].fi >> g[i].se;
	}
	
	// DP
	memset(dp, 0, sizeof dp);
	dp[0][0][0][0][0][0] = 1;
	
	for(int i = 0; i < n; ++i) {
		for(int tag1 = 0; tag1 <= 15; ++tag1) {
			for(int tag2 = 0; tag2 <= 15; ++tag2) {
				for(int tag3 = 0; tag3 <= 15; ++tag3) {
					for(int tag4 = 0; tag4 <= 15; ++tag4) {
						for(int tag5 = 0; tag5 <= 15; ++tag5) {
							int cur = dp[i][tag1][tag2][tag3][tag4][tag5];
							if(cur == 0) continue;
							//db(i);
							//db(cur);
							//cerr << tag1 << tag2 << tag3 << tag4 << tag5;
							vector<int> d(6,0);
							for(auto x : a[i + 1]) {
								d[fi(x)]++;
							}
							//cerr << "\t";
							//for(int i = 1; i <= 5; ++i) cerr << d[i] << " ";
							dp[i + 1][tag1][tag2][tag3][tag4][tag5] += cur;
							if(tag1 + d[1] > 15) continue;
							if(tag2 + d[2] > 15) continue;
							if(tag3 + d[3] > 15) continue;
							if(tag4 + d[4] > 15) continue;
							if(tag5 + d[5] > 15) continue;
							dp[i + 1][tag1 + d[1]][tag2 + d[2]][tag3 + d[3]][tag4 + d[4]][tag5 + d[5]] += cur;
							//cerr << "\n";
						}
						
					}
				}
			}
		}
	}
	
	int res = 0;
	for(int tag1 = g[1].fi; tag1 <= g[1].se; ++tag1) {
		for(int tag2 = g[2].fi; tag2 <= g[2].se; ++tag2) {
			for(int tag3 = g[3].fi; tag3 <= g[3].se; ++tag3) {
				for(int tag4 = g[4].fi; tag4 <= g[4].se; ++tag4) {
					for(int tag5 = g[5].fi; tag5 <= g[5].se; ++tag5) {
						res += dp[n][tag1][tag2][tag3][tag4][tag5];
					}
				}
			}
		}
	}
	if(g[1].fi == 0 && g[2].fi == 0 && g[3].fi == 0 && g[4].fi == 0 && g[5].fi == 0) {
		--res;
	}
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}