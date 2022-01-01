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
const int MAXN1 = 1e5+5;
const int MAXN2 = 3e6+5;

int m,n;

bool p[MAXN2];
int f[MAXN2];

void sieve(int lim) {
	for(int i=2;i*i <= lim;++i) {
		if(!p[i]) for(int j=i*i;j<=lim;j += i) p[j] = 1;
	}
	
	for(int i=2;i<=lim;++i) {
		f[i] = f[i-1] + (!p[i]);
	}
}

signed main() {
	fast_cin();
	
	cin >> m >> n;
	
	sieve(m+n);
	
	int ans = 0;
	for(int i=1;i<=m;++i) {
		ans += f[i+n] - f[i];
		//cout << ans << " ";
	}
	// for(int i=1;i<=n;++i) {
		// ans += f[i+m] - f[i-1];
	// }
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}