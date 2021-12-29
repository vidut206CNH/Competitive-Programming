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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int t;
int a[MAXN1];
int b[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;++i) cin >> a[i];
		int l = 1, r = a[n];
		int res = 0;
		
		while(l <= r) {
			int mid = (l+r) >> 1;
			
			for(int i=1;i <= n;++i) {
				b[i] = a[i];
				//cout << b[i] << " ";
			}
			
			
			bool bad = 0;
			int minn = 2e15;
			
			for(int i = n; i >= 3;--i) {
				if(b[i] < mid) {
					bad = 1;
					break;
				}
				int m = min(a[i], b[i] - mid);
				//cout << m << " ";
				if(m%3) m = m/3*3;
				
				b[i] -= m;
				b[i-2] += m/3*2;
				b[i-1] += m/3;
				//cout << b[i] << " ";
			}
			
			for(int i=1;i <= n;++i) {
				if(b[i] < mid) {
					bad = 1;
					break;
				}
				minn = min(minn, b[i]);
			}
			
			if(bad) {
				r = mid - 1;
			}
			else {
				res = max(res, minn);
				l = mid + 1;
			}
			//cout << mid <<  "\n\n";
		}
		
		cout << res << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}