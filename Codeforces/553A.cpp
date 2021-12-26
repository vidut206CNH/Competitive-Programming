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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;

int k;
int a[MAXN1];
int C[MAXN1][MAXN1];


signed main() {
	fast_cin();

	C[0][0] = 1;
	
	for(int i=1;i<=1000;++i) {
		C[i][0] = 1;
		C[i][i] = 1;
		
		for(int j=1;j < i;++j) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
		}
	}
	
	cin >> k;
	int sum = 0,ans = 1;
	for(int i=1;i<=k;++i) {
		cin >> a[i];
		sum += a[i];
		ans = (ans * C[sum-1][a[i] - 1])%MOD;
		//cout << ans << " ";
	}
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}