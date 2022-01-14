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
const int MAXN2 = 1e6+5;

int m,n;

void solve() {
	cin >> m >> n;
	vector< vector<int> > p(m+5, vector<int>(n+5));
	vector<bool> b(n+1,0);
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> p[i][j];
		}
	} 
	
	auto check = [&](int x) {
		b.assign(n+1, 0);
		bool ok = 0;
		for(int i=1;i<=m;++i) {
			int cnt = 0;
			for(int j=1;j<=n;++j) {
				if(p[i][j] >= x) {
					cnt++;
					b[j] = true;
				}
			}
			ok |= (cnt > 1);
		}
		for(int i=1;i<=n;++i) ok &= b[i];
		return ok;
	};
	
	int l=1,r=1e9,res = 0;
	
	while(l<=r) {
		int mid = (l+r) >> 1;
		if(check(mid)) {
			res = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	
	cout << res << "\n";
	
}


signed main() {
	fast_cin();
	int t;
	cin >> t;
	while(t--) {
		solve();
	}	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}