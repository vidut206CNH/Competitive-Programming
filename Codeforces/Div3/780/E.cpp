/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int MAXN1 = 4e3+5;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

int t;
int n;
bool a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];
int cross[MAXN1][MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				char c;
				cin >> c;
				a[i][j] = c - '0';
				a[i + n][j] = a[i][j];
				a[i][j + n] = a[i][j];
				a[i + n][j + n] = a[i][j];
			}
		}
		
		for(int i = 1; i <= 2*n; ++i) {
			for(int j = 1; j <= 2*n; ++j) {
				f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
				
				cross[i][j] = a[i][j] + cross[i - 1][j - 1];
			}
		}
		
		int res = MOD;
		
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				int u = i + n - 1;
				int v = j + n - 1;
				
				int sum = f[u][v] - f[i - 1][v] - f[u][j - 1] + f[i - 1][j - 1];
				sum += (n  - 2*(cross[u][v] - cross[i - 1][j - 1]));
				
				res = min(res, sum);
				//db(res);
			}
			//cerr << "\n";
		}
		//cerr << "\n";
		
		cout << res << "\n";
	}
	

	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}