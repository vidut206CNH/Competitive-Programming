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
const int MAXN1 = 1005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int res[MAXN1][MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	if(k > n*n) {
		cout << -1;
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			if(k == 0) break;
			
			if(i == j) {
				if(k&1) {
					res[i][j] = 1;
					--k;
				}
				else if(res[i][j] != 1) {
					res[i][j] = 1;
					res[i + 1][j + 1] = 1;
					k -= 2;
				}
			}
			
			else {
				k -= 2;
				res[i][j] = 1;
				res[j][i] = 1;
			}
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cout << res[i][j] << " \n"[j == n];
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}