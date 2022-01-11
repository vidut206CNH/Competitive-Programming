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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e3+5;
const int inf = 1e18;
const int base = 13;
int t;
bool ok[MAXN1];
pii p[MAXN1];

char a[MAXN2][MAXN2];
char b[MAXN2];

signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		
		int n,m;
		cin >> n >> m;
		bool good = 1;
		cin.ignore();
		
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				cin >> a[i][j];
				a[i][j] = a[i][j] - '0' + 1;
				if(j > 1) {
					ok[a[i][j-1]*base + a[i][j]] = 1;
					p[a[i][j-1]*base + a[i][j]] = {j-1, i};
				}
				if(j > 2) {
					ok[a[i][j-2]*base*base + a[i][j-1]*base + a[i][j]] = 1;
					p[a[i][j-2]*base*base + a[i][j-1]*base + a[i][j]] = {j-2, i};
				}
/*				db((int)a[i][j]);
				cerr << "\n";*/
			}
			cin.ignore();
		}
		for(int i=1;i<=m;++i) {
			cin >> b[i];
			b[i] = b[i] - '0' + 1;
		}
		cin.ignore();
		
		vector<int> dp(m+1, -1);
		dp[0] = 0;
		
		for(int i=1;i<=m;++i) {
			
			if(i > 1) {
				int val = b[i-1]*base + b[i];
				if(dp[i-2] != -1 && ok[val]) {
					dp[i] = i-2;
				}	
			}
			if(i > 2) {
				int val = b[i-2]*base*base + b[i-1]*base + b[i];
				if(dp[i-3] != -1 && ok[val]) {
					dp[i] = i-3;
				}
			}
		}
		vector< pair<pii, int> > res;
		good = (dp[m] != -1);
		
		if(dp[m] != -1) {
			//db(m);
			int pos = m;
			while(pos != 0) {
				if(pos - dp[pos] == 2) {
					int val = b[pos-1]*base + b[pos];
					res.push_back({{p[val].fi, p[val].fi + 1}, p[val].se});
				}
				else {
					int val = b[pos-2]*base*base + b[pos-1]*base + b[pos];
					res.push_back({{p[val].fi, p[val].fi + 2}, p[val].se});
				}
				pos = dp[pos];
			}
		}
		
		reverse(res.begin(),res.end());
		
		
		
		//memset
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				if(j > 1) {
					ok[a[i][j-1]*base + a[i][j]] = 0;
				}
				if(j > 2) {
					ok[a[i][j-2]*base*base + a[i][j-1]*base + a[i][j]] = 0;
				}
			}
		}
		
		//db(good);
		
		//cerr << "\n\n";
		if(good) {
			cout << sz(res) << "\n";
			for(auto x : res) cout << x.fi.fi << " " << x.fi.se << " " << x.se << "\n";
		}
		
		else cout << "-1\n";
	}	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}