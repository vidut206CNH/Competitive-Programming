/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int m,n,q;
int a[503][503];
int M[503][503][11][11];

int main() {
	fast_cin();
	
	cin >> m >> n >> q;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	for(int r = 1; r <= m; ++r) {
		for(int c = 1; c <= n; ++c) {
			M[r][c][0][0] = a[r][c];
		}
	}
	
	for(int kr = 1; (1 << kr) <= m; ++kr) {
		for(int r = 1; r <= m; ++r) {
			for(int c = 1; c <= n; ++c) {
				// if(r + (1 << kr) - 1 > m) continue;
				M[r][c][kr][0] = min(M[r][c][kr - 1][0], M[r + (1 << (kr - 1))][c][kr - 1][0]);
			}
		}
	}
	for(int kc = 1; (1 << kc) <= n; ++kc) {
		for(int r = 1; r <= m; ++r) {
			for(int c = 1; c <= n; ++c) {
				
				if(c + (1 << kc) - 1 > n) continue;
				
				M[r][c][0][kc] = min(M[r][c][0][kc - 1], M[r][c + (1 << (kc - 1))][0][kc - 1]);
			}
		}
	}
	
	for(int r = 1; r <= m; ++r) {
		for(int c = 1; c <= n; ++c) {
			for(int kr = 1; (1 << kr) <= m; ++kr) {
				for(int kc = 1; (1 << kc) <= n; ++kc) {
					if(r + (1 << kr) - 1 > m) continue;
					if(c + (1 << kc) - 1 > n) continue;
					M[r][c][kr][kc] = min({
							M[r][c][kr - 1][kc - 1],
							M[r + (1 << (kr - 1))][c][kr - 1][kc - 1],
							M[r][c + (1 << (kc - 1))][kr - 1][kc - 1],
							M[r + (1 << (kr - 1))][c + (1 << (kc - 1))][kr - 1][kc - 1]
					});
					
				}
			}
		}
	}
	
	while(q--) {
		int x,y,u,v;
		cin >> x >> y >> u >> v;
		int kc = log2(v - y + 1);
		int kr = log2(u - x + 1);
		
		cout << min({
			M[x][y][kr][kc],
			M[u - (1 << kr) + 1][y][kr][kc],
			M[x][v - (1 << kc) + 1][kr][kc],
			M[u - (1 << kr) + 1][v - (1 << kc) + 1][kr][kc]
		}) << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}