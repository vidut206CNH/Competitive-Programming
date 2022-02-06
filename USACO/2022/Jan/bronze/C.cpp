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
int a[MAXN1];
int b[MAXN1];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=1;i<=n;++i) cin >> a[i];
		
		int l = 0, r = *min_element(a + 1, a + n + 1), res = -1;
		while(l <= r) {
			int mid = (l+r) >> 1;
			//db(mid);
			for(int i=1;i<=n;++i) b[i] = a[i];
			bool bad = false;
			
			for(int i=1;i<=n;++i) {
				if(i == n) {
					if(b[i] < mid) {
						bad = true;
					}
				} else {
					if(b[i] < mid) {
						bad = true;
						break;
					}
					
					int diff = b[i] - mid;
					b[i] -= diff;
					b[i+1] -= diff;
				}
			}
			
			if(bad) r = mid - 1;
			else {
				if(b[n] == mid) res = mid;
				l = mid + 1;
			}
		}
		
		if(res == -1) cout << res << "\n";
		else {
			int cnt = 0;
			for(int i=1;i<=n;++i) {
				int diff = a[i] - res;
				cnt += diff;
				a[i] -= diff;
				a[i+1] -= diff;
			}
			
			cout << cnt*2 << "\n";
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}