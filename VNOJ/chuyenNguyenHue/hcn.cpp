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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

int m,n,k;
bool a[MAXN1][MAXN1];
bool one[MAXN1];
int f[MAXN1];

signed main() {
	fast_cin();
	
	cin >> m >> n >> k;
	memset(a, true, sizeof a);
	for(int i = 1; i <= k; ++i) {
		int x,y;
		cin >> x >> y;
		a[x][y] = false;
	}
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(one[j] && a[i][j]) {
				continue;
			}
			one[j] |= 
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}