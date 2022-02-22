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

int n;

signed main() {
	fast_cin();
	int t;
	cin >> t;
	while(t -- ) {
		
		cin >> n;
		vector<vector<int> > a(n, vector<int>(5));
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 5; ++j) {
				cin >> a[i][j];
			}
		}
		
		vector<int> best(5,inf);
		int res = -1;
		
		for(int i = 0; i < n; ++i) {
			int win = 0;
			for(int j = 0; j < 5; ++j) {
				win += (a[i][j] < best[j]);
			}
			
			if(win >= 3) {
				res = i;
				best = a[i];
			}
		}
		
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			if(i != res) {
				int win = 0;
				for(int j = 0; j < 5; ++j) {
					win += (best[j] < a[i][j]);
				}
				
				ok &= (win >= 3);
			}
		}
		
		if(ok) cout << res + 1;
		else cout << -1;
		cout << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}