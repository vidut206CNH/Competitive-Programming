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
const int MAXN2 = 7e5+5;
const int inf = 1e18;

int n,m;

int dp[2][MAXN2];
int c[] = {4, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int dp[10];

signed main() {
	fast_cin();
	
	cin >> n >> m;
	vector<int> p(m);
	for(int i = 0; i < m; ++i) {
		cin >> p[i];
	}
	
	memset(dp, -1, sizeof dp);
	
	for(auto x : p) {
		dp[c[x]] = x;
	}	
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}