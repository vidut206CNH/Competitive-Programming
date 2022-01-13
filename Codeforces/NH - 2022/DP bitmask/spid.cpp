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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int l1,l2,l3,c1,c2,c3;
int n;
int s,t;
int f[MAXN1];
int dp[MAXN1];

signed main() {
	fast_cin();
	
	cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
	cin >> n >> s >> t;
	for(int i=2;i<=n;++i) {
		int x;
		cin >> x;
		f[i] = f[i-1] + x;
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}