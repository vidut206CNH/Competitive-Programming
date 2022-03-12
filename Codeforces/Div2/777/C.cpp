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
int t;
char a[MAXN1][MAXN1];
bool b[MAXN1][MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> m >> n;
		int sum = 0; 
		bool bad = false;
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				cin >> a[i][j];
				sum += (a[i][j] - '0');
			}
		}
		bad = (a[1][1] == '1');
		if(bad) {
			cout << -1 << "\n";
			continue;
		}
		vector<vector<int> > res;
		for(int i = 1; i <= n; ++i) {
			if(i&1) {
				for(int j = 1; j <= n; ++j) {
					if(b[i][j]  + '0' == a[i][j]) continue;
					
					if(j == n) {
						if(b[i][j] == true) {
							b[i][j] ^= 1;
							b[i + 1][j] ^= 1;
							res.push_back({i, j, i + 1, j});
						}
					}
					 
					else {
						b[i][j] ^= 1;
						b[i][j + 1] ^= 1;
						res.push_back({i, j, i, j + 1});
					}
				}
			}
			else {
				for(int j = n; j >= 1; --j) {
					if(b[i][j] + '0' == a[i][j]) continue;
					if(j == 1) {
						b[i][j] ^= 1;
						b[i + 1][j] ^= 1;
						res.push_back({i, j, i + 1, j});
					}
					
					else {
						res.push_back({i, j, i, j - 1});
					}
				}
			}
		}
		
		cout << sz(res) << "\n";
		for(auto x : res) {
			for(auto val : x) cout << val << " ";
			cout << "\n";
		}
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}