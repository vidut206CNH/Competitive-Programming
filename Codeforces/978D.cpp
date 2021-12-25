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

int n;
vector<int> a[MAXN1];
int b[MAXN1];

signed main() {
	fast_cin();
	cin >> n;
	if(n == 1) {
		cout << 0;
		exit(0);
	}
	
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		a[i] = {x,x-1,x+1};
	}
	int ans = 1e6;
	for(int i=0;i<3;++i) {
		for(int j=0;j<3;++j) {
			int d = a[2][j] - a[1][i];
			b[1] = a[1][i];
			b[2] = a[2][j];
			
			int m = (i != 0) + (j != 0);
			bool ok = 1;
			for(int pos = 3;pos <= n;++pos) {
				bool good = 0;
				for(int r = 0;r < 3;++r) {
					if(a[pos][r] == b[pos-1] + d) {
						b[pos] = a[pos][r];
						good = 1;
						m += (r != 0);
					} 
				}
				ok &= good;
			}
			if(ok) {
				ans = min(ans, m);
			}
		}
	}
	if(ans != (int)1e6) cout << ans;
	else cout << -1;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}