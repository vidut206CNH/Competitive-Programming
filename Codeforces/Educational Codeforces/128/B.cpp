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
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int a[10][10];
int f[10][10];

signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		memset(f, 0, sizeof f);
		int m,n;
		cin >> m >> n;
		int sum = 0;
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				char c;
				cin >> c;
				a[i][j] = (c == 'E' ? 0 : 1);
				sum += a[i][j];
			}
		}
		bool ok = false;
		
		for(int i = m; i > 0; --i) {
			for(int j = n; j > 0; --j) {
				f[i][j] = f[i + 1][j] + f[i][j + 1] - f[i + 1][j + 1] + a[i][j];
				ok |= (f[i][j] == sum && a[i][j]);
			}
		}
		
		cout << (ok ? "YES\n" : "NO\n");
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}