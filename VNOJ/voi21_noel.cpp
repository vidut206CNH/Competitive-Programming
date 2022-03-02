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
const int MAXN1 = 1e2+5;
const int MAXN2 = 2e3+5;
const int inf = 1e18;

int n,d;
int a[MAXN2];
bool dp[MAXN1][MAXN1][MAXN1];
// dp(choose , k, x, y) = true/false xay dung duoc k cap (a_i,a_j) thoa man 
// va i <= x && j <= y
// Dpt: O(n^3)



void sub2() {

	int res = 0;
	
	memset(dp[0], true, sizeof dp[0]);
	
	for(int k = 1; k <= n; ++k) {
		for(int x = 1; x <= 2*n; ++x) {
			for(int y = x + k; y <= 2*n; ++y) {
					
				if(abs(a[x] - a[y]) <= d) {
					for()
				}
				

				if(dp[k][x][y]) res = k;
			}
		}
	}
	
	cout << res;
	
}

signed main() {
	fast_cin();
	
	cin >> n >> d;
	for(int i = 1; i <= 2*n; ++i) {
		cin >> a[i];
	}
	
	sub2();
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}