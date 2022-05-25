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
const int MAXN1 = 43;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,p,q;
int a[MAXN1][MAXN1][MAXN1][MAXN1];
int f[MAXN1][MAXN1][MAXN1][MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> m >> p >> q;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= p; ++k) {
				for(int t = 1; t <= q; ++t) {
					cin >> a[i][j][k][t];
				}
			}
		}
	}	
	
	
	// calc f[i][j][k][t]
	memset(f, 0, sizeof f);
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= p; ++k) {
				for(int t = 1; t <= q; ++t) {
					f[i][j][k][t] = 
						f[i - 1][j][k][t]
						+f[i][j - 1][k][t]
						+f[i][j][k - 1][t]
						+ f[i - 1][j - 1][k - 1][t]
						- f[i - 1][j - 1][k][t]
						- f[i - 1][j][k - 1][t]
						- f[i][j - 1][k - 1][t]
						+ a[i][j][k][t];
/*					if(t == 1) {
						db(i);
						db(j);
						db(k);
						db(a[i][j][k][t]);
						db(f[i][j][k][t]);
						cerr << "\n";
					}*/
				}
			}
		}
	}
	
	int tt;
	cin >> tt;
	while(tt--) {
		
		int x1, y1, z1, t1, x2, y2, z2, t2;
		cin >> x1 >> y1 >> z1  >> t1;
		cin >> x2 >> y2 >> z2 >> t2;
		int res = 0;
		for(int t = t1; t <= t2; ++t) {
			res += 	
				f[x2][y2][z2][t]
				- f[x1 - 1][y2][z2][t]
				- f[x2][y1 - 1][z2][t]
				- f[x2][y2][z1 - 1][t]
				+ f[x1 - 1][y1 - 1][z2][t]
				+ f[x1 - 1][y2][z1 - 1][t]
				+ f[x2][y1 - 1][z1 - 1][t]
				- f[x1 - 1][y1 - 1][z1 - 1][t];
		}
		
		cout << res << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}