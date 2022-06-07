/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int t;
int n,k;
long long a[MAXN1];
long long f[MAXN1];

int main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) f[i] = f[i - 1] + a[i];
		
		if(k < n) {
			long long res = 0;
			for(int i = 0; i <= n - k; ++i) {
				res = max(res, f[i + k] - f[i]);
			}
			
			cout << res + 1LL*(k)*(k - 1)/2 << "\n";
			continue;
		}
		
		else {
			cout << f[n] + (1LL*n*(k - 1) - 1LL*(n)*(n - 1)/2) << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}