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
const int MAXN1 = 40;
const int MAXN2 = 1e6+5;

int f[MAXN1];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	f[0] = 1;
	for(int i=1;i<=31;++i) {
		f[i] = f[i-1]*2%MOD;
	}
	
	while(t--) {
		int n,m;
		cin >> n >> m;
		--n;
		int ans = 0;
		for(int i=1;i<=m;++i) {
			int l,r,x;
			cin >> l >> r >> x;
			ans |= x; 
		}
		ans = (ans%MOD*f[n]%MOD)%MOD;
		
		cout << ans << "\n";	
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}