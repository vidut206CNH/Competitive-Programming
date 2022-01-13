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
#define g(x,i) ((x) >> (i) & 1)
typedef pair<int,int> pii;

const int MOD = 1e9;
const int MAXN1 = 1LL << 10;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int dp[15][MAXN1];
int n,m;


bool check(const int& A, const int& B) {
	for(int i=0; i < (n-1); ++i) {
		if(g(A, i) && g(A, i+1) && g(B, i) && g(B, i+1)) {
			return false;
		}
		if(!g(A, i) && !g(A, i+1) && !g(B, i) && !g(B, i+1)) {
			return false;
		}
	}
	return true;
}

signed main() {
	fast_cin();
	
	cin >> m >> n;
	int lim = (1LL << n);
	int res = 0;
	for(int i=1;i<=m;++i) {
		for(int state = 0;state < lim; ++state) {
			if(i==1) {
				dp[i][state] = 1;
				continue;
			}
			for(int pre = 0;pre < lim; ++pre) {
				if(check(pre,state)) {
					dp[i][state] = (dp[i-1][pre] + dp[i][state])%MOD;
				}
			}
			if(i == m) res = (res + dp[i][state])%MOD;
		}	
	}
	
	cout << res;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}