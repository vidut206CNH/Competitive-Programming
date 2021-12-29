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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;



signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		int m,n,r_a, c_a, r_b,c_b;
		cin >> m >> n >> r_a >> c_a >> r_b >> c_b;
		int dx = 1;
		int dy = 1;
		int ans = 0;
		while(r_a != r_b && c_a != c_b) {
			ans++;
			//if(ans == 7) break;
			r_a += dx;
			c_a += dy;
			if(r_a > m) {
				r_a = m-1;
				dx = -dx;
			}
			if(c_a > n) {
				c_a = n-1;
				dy = -dy;
			}
		}
		cout << ans << "\n"; 
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}