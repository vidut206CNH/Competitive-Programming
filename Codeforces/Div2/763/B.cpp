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

int t;
pair<pii, int> a[MAXN1];
int res[MAXN1];
pii f[MAXN1];

bool comp(const pair<pii, int>&A, const pair<pii, int>& B) {
	if(A.fi.se == B.fi.se) return A.fi.fi < B.fi.fi;
	return A.fi.se > B.fi.se;
}

signed main() {
	fast_cin();
		
	cin >> t;
	while(t--) {	
		int n;
		cin >> n;
		memset(res, 0, sizeof res);
		for(int i=1;i <= n;++i) {
			cin >> a[i].fi.fi >> a[i].fi.se;
			a[i].se = i;
			f[i] = {a[i].fi.fi, a[i].fi.se};
		}
		
		sort(a+1,a+n+1,comp);
		int m = n;
		for(int i=2;i<=n;++i) {
			if(m == a[i].fi.se) {
				res[a[i-1].se] = a[i].fi.fi - 1;
			} else {
				res[a[i-1].se] = m;
				m = a[i].fi.se;
			}
		}
		for(int i=1;i<=n;++i) {
			cout << f[i].fi << " " << f[i].se << " ";
			if(res[i] != 0) cout << res[i] << "\n";
			else cout <<  f[i].fi << "\n";
			if(i == n) cout << "\n";
		}
		//cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}