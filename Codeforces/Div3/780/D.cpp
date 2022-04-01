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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int t,n;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		
		int res = 0;
		pii v = {0, n};
		int l = 1,r = 1;
		while(r <= n) {
			if(a[r] == 0) {
				++r;
				continue;
			}
			l = r;
			int ok = 0;
			while(r <= n && a[r] != 0) {
				ok += (a[r] < 0);
				
				++r;
			}
			--r;
			if(a[r] != 0) {
				int cnt = 0;
				for(int i = l; i <= r; ++i) cnt += (abs(a[i]) == 2);
				if(ok%2 == 0) {
					if(cnt > res) {
						res = cnt;
						v.fi = l - 1;
						v.se = n - r;
					}
				}
				else {
					int cntl = 0, cntr = 0, l1 = l, r1 = r;
					
					while(l1 <= r && a[l1] > 0) {
						cntl += (abs(a[l1]) == 2);
						++l1;
					}
					cntl += (abs(a[l1]) == 2);
					
					while(r1 >= l && a[r1] > 0) {
						cntr += (abs(a[r1]) == 2);
						--r1;
					}
					
					cntr += (abs(a[r1]) == 2);
/*					db(t);
					db(cntl);
					db(cntr);
					cerr << "\n";*/
					if(cntl > cntr) {
						cnt -= cntr;
						if(cnt > res) {
							res = cnt;
							v.fi = l - 1;
							v.se = n - r1 + 1;
						}
					}
					
					else {
						cnt -= cntl;
						if(cnt > res) {
							res = cnt;
							v.fi = l1;
							v.se = n - r;
						}
					}
				}
				
			}
			
			++r;
		}
		
		cout << v.fi << " " << v.se << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}