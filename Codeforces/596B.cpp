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
const int MAXN1 = 2e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;
int a[MAXN1];
int b[2*MAXN1];
unordered_map<int,int> ma,mb;

signed main() {
	fast_cin();
	
	cin >> n >> m;
	
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		ma[a[i]]++;
	}
	for(int i=1;i<=n;++i) {
		cin >> b[i];
		mb[b[i]]++;
	}
	int ans = m;
	for(int k=1;k <= n;++k) {
		int d = (b[k] + m - a[1])%m;
		bool ok = 1;
		for(int i=1;i <= n; ++i) {
			ok &= (ma[a[i]] == mb[(d + a[i])%m]);
			//db(ok);
		}
		//db(d);
		//cerr << "\n";
		if(ok) ans = min(ans, d);
	}
	
	cout << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}