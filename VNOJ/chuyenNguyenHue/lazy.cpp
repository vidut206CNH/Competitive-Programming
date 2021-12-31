/*
	Author : vidut_206_CNH
	Link problem: 
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
const int MAXN2 = 1e6+5;

pii a[MAXN2];
int f[MAXN2];
int n,k;

signed main() {
	fast_cin();
	
	cin >> n >> k;
	
	for(int i=1;i<=n;++i) {
		cin >> a[i].se >> a[i].fi;
	}
	
	sort(a+1,a+n+1, [](const pii& A, const pii& B) {return A.fi < B.fi;});
	
	for(int i=1;i<=n;++i) {
		f[i] = f[i-1] + a[i].se;
	}
	int lpos = 1,rpos = 1;
	int ans = -INF;
	while(rpos <= n) {
		if(a[rpos].fi - a[lpos].fi + 1 <= 2*k + 1) {
			ans = max(ans ,f[rpos] - f[lpos-1]);
			rpos++;
		}	
		else lpos++;
	}	
	
	cout << ans << "\n";
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
