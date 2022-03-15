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
const int MAXN1 = 2005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

string s;
int dp[MAXN1][MAXN1];
pii trace[MAXN1][MAXN1];
string res;
// dp(l,r)

void find(int l, int r, int u) {
	if(l == r) {
		res[u] = s[l];
		return;
	}
	if(l + 1 == r && s[l] == s[r]) {
		res[u] = res[u + 1] = s[l];
		return;
	}
	
	int l1 = trace[l][r].fi;
	int r1 = trace[l][r].se;
	
	if(s[l] == s[r]) {
		res[u] = s[l];
		res[sz(res) - u - 1] = s[r];
		find(l1, r1, u + 1);
	}
	else find(l1, r1, u);
}


signed main() {
	fast_cin();
	
	cin >> s;
	
	for(int r = 0; r < sz(s); ++r) {
		for(int l = r; l >= 0; --l) {
			if(l == r) dp[l][r] = 1;
			else {
				if(s[l] == s[r]) {
					dp[l][r] = dp[l + 1][r - 1] + 2;
					trace[l][r] = {l + 1, r - 1};
				}
				else {
					dp[l][r] = dp[l + 1][r];
					trace[l][r] = {l + 1,r};
					if(dp[l][r] < dp[l][r - 1]) {
						dp[l][r] = dp[l][r - 1];
						trace[l][r] = {l, r- 1};
					}
				}
			}
		}
	}
	res.resize(dp[0][sz(s) - 1]);
	find(0, sz(s) - 1, 0);
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}