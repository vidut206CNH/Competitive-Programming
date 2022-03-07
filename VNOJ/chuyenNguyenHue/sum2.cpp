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
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,q;
int a[MAXN1][MAXN1];
int diff[MAXN1][MAXN1];




signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	
	cin >> q;
	while(q--) {
		int x, y, u, v, val;
		cin >> x >> y >> u >> v >> val;
		diff[x][y] += val;
		diff[x][v + 1] -= val;
		diff[u + 1][y] -= val;
		diff[u + 1][v + 1] += val;
	}
	
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			diff[i][j] += (diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1]);
			cout << diff[i][j] + a[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}