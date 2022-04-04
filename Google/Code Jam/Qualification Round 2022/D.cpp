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
char res[30][30];

signed main() {
	fast_cin();
	
	
	cin >> t;
	for(int tt = 1; tt <= t; ++tt) {
		cout << "Case #" << tt << ":" << "\n";
		int r,c;
		cin >> r >> c;
		r = r*2 + 1;
		c = c*2 + 1;
		for(int i = 1; i <= r; i += 2) {
			for(int j = 1; j <= c; j += 2) {
				res[i][j] = '+';
			}
			
			for(int j = 2;j <= c; j += 2) {
				res[i][j] = '-';
			}
		}
		

		
		for(int i = 2; i <= r; i += 2) {
			for(int j = 1; j <= c; j += 2) {
				res[i][j] = '|';
			}
			
			for(int j = 2; j <= c; j += 2) {
				res[i][j] = '.';
			}
		}
		
		for(int i = 1; i <= 2; ++i) {
			for(int j = 1; j <= 2; ++j) {
				res[i][j] = '.';
			}
		}
		
		for(int i = 1; i <= r; ++i) {
			for(int j = 1; j <= c; ++j) {
				cout << res[i][j];
			}
			cout << "\n";
		}
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}