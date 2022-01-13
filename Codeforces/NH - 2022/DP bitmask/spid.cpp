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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,lim,des;
int w[MAXN1],v[MAXN1];
double dp[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> lim >> des;
	
	for(int i=1;i<=n;++i) {
		cin >> w[i] >> v[i];
	}	
	dp[0] = 0.0;
	
	for(int i=1;i<=n;++i) {
		int cost = v[i],sum = w[i];
		dp[i] = des/(1.0*v[i]) + dp[i-1]; 
		for(int j=i-1;j>=1;--j) {
			sum += w[j];
			if(sum > lim) break;
			cost = min(cost, v[j]);
			dp[i] = min(dp[i], des/(1.0*cost) + dp[j-1]);
		}
		db(dp[i]);
		cerr << "\n";
	}
	
	cout << fixed << setprecision(15) << dp[n];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}