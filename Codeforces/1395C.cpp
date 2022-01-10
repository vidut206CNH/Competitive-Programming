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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 205;
const int MAXN2 = (1LL << 10) + 5;
const int inf = 1e18;

int n,m;
int a[MAXN1];
int b[MAXN1];
bool dp[MAXN1][MAXN2];

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	for(int i=1;i<=m;++i) cin >> b[i];
	dp[0][0] = 1;
	
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			for(int state=0;state < (1LL << 10);++state) {
				if(dp[i-1][state]) dp[i][(state|(a[i]&b[j]))] = 1;
			}
		}
	}
	
	for(int i=0;i< (1LL << 10);++i) {
		if(dp[n][i]) {
			cout << i;
			exit(0);
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}