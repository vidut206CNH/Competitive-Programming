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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int f[MAXN1],s[MAXN1];
int res[MAXN1];
int dp[2][MAXN1];
stack<int> d;

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		f[i] = f[i-1] + a[i];
	}

	
	for(int i=1;i<=n;++i) {
		while(!d.empty() && a[d.top()] >= a[i]) d.pop();
		if(d.empty()) {
			dp[0][i] = f[i-1] - (i - 1)*(a[i]);
		} else {
			dp[0][i] = f[i-1] - f[d.top()] - (i- 1 - d.top())*a[i] + dp[0][d.top()];
		}
		d.push(i);
	}
	while(!d.empty()) d.pop();
	int minn = 1e18+7, best = 0;
	for(int i=n;i>=1;--i) {
		while(!d.empty() && a[d.top()] >= a[i]) d.pop();
		if(d.empty()) {
			dp[1][i] = f[n] - f[i] - (n - i)*a[i];
		} else {
			dp[1][i] = f[d.top() - 1] - f[i] - (d.top() - i - 1)*a[i] + dp[1][d.top()];
			
		}
		d.push(i);
		if(minn > dp[1][i] + dp[0][i]) {
			minn = dp[1][i] + dp[0][i];
			best = i;
		}
	}
	int pre = a[best];
	res[best] = a[best];
	for(int i=best - 1; i>= 1;--i) {
		if(a[i] > pre) res[i] = pre;
		else res[i] = a[i];
		pre = res[i];
	}
	pre = a[best];
	for(int i = best + 1; i<= n;++i) {
		if(a[i] > pre) res[i] = pre;
		else res[i] = a[i];
		pre = res[i];
	}
	
	for(int i=1;i<=n;++i) cout << res[i] << " ";
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}