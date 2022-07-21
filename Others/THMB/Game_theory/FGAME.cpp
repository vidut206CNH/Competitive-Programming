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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;

int n,m;
bool dp[MAXN1][MAXN1];
int a[MAXN1][MAXN1];
int sum[MAXN1][MAXN1];
int row[MAXN1][3], col[MAXN1][3];

int main() {
	fast_cin();
	
	while(cin >> m >> n) {
		memset(row, false, sizeof row);
		memset(col, false, sizeof col);
		memset(dp, false, sizeof dp);
		
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				cin >> a[i][j];
				sum[i][j] = (a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + 6)%3;
			}
		}
		
		for(int x = 1; x <= m; ++x) {
			for(int y = 1; y <= n; ++y) {
				row[x][0] = col[y][0] = true;
				
				int d = (sum[x][y] + 2)%3;
				if(row[x][d]) dp[x][y] = true;
				if(col[y][d]) dp[x][y] = true;
				
				if(dp[x][y] == false) {
					row[x][sum[x][y]] = true;
					col[y][sum[x][y]] = true;
				}
				
			}
		}	
		
		
		cout << dp[m][n] << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}