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
const int MAXN1 = 703;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int dp[MAXN1][MAXN1];
int trace[MAXN1][MAXN1];
string s;
char res[MAXN1];


void calc(int l, int r) {
	res[l] = '(';
	res[r] = ')';
	if(l + 1 == r) return;
	if(trace[l][r] == -1) {
		calc(l + 1, r - 1);
	} else {
		int mid = trace[l][r];
		calc(l, mid);
		calc(mid + 1, r);
	}
}


signed main() {
	fast_cin();
	
	cin >> s;
	memset(dp, -1, sizeof dp);
	
	for(int r = 1; r < sz(s); ++r) {
		for(int l = r - 1; l >= 0; --l) {
			if(s[l] == s[r] && s[l] == '(') continue;
			if(s[l] == s[r] && s[l] == ')') continue;
			if(s[l] == ')' || s[r] == '(') continue;
			
			for(int mid = l + 1; mid < r - 1; ++mid) {
				if(dp[l][mid] != -1 && dp[mid + 1][r] != -1) {
					int val = max(dp[l][mid], dp[mid + 1][r]);
					if(val > dp[l][r]) {
						dp[l][r] = val;
						trace[l][r] = mid;
					}
				}
			}
			if(l + 1 == r || dp[l + 1][r - 1] != -1) {
				int val = 0;
				if(l + 1 == r) val = 1;
				else val = dp[l + 1][r - 1] + 1;
				if(val > dp[l][r]) {
					dp[l][r] = val;
					trace[l][r] = -1;
				}
			}
		}
	}
	
	calc(0, sz(s) - 1);
	
	for(int i = 0; i < sz(s); ++i) cout << res[i];
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}