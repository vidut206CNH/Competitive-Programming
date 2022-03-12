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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
char a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];
int s[MAXN1][MAXN1];

signed main() {
	fast_cin();
	int t;
	cin >> t;
	while(t--) {
		cin >> m >> n;
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		bool bad = false;
		
/*		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(a[i][j] == '0') {	
					f[i][j] = 0;
				}
				else f[i][j] = 1 + f[i - 1][j];
			}
		}
		
		for(int i = m; i >= 1; --i) {
			for(int j = 1; j <= n; ++j) {
				if(a[i][j] == '0') {
					s[i][j] = 0;
				} else s[i][j] = 1 + s[i + 1][j];
			}
		}
		
		
		for(int i = 1; i <= m; ++i) {
			bool good = true;
			int val = -1;
			
			for(int j = 1; j <= n; ++j) {
				if(val == -1 && f[i][j] != 0) val = f[i][j];
				good &= (f[i][j] == val || f[i][j] == 0); 
			}
			
			val = -1;
			for(int j = 1; j <= n; ++j) {
				if(val == -1 && s[i][j] != 0) val = s[i][j];
				good &= (s[i][j] == val || s[i][j] == 0);
			}
			
			if(!good) {
				bad = true;
				break;
			}
		}
		
		// init
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				s[i][j] = 0;
				f[i][j] = 0;
			}
		}*/
		
		for(int i = 1; i < m; ++i) {
			for(int j = 1; j < n; ++j) {
				bad |= (a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] == 3*('1') + '0');
			}
		}
		
		cout << (bad ? "NO\n" : "YES\n");
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}