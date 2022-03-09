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

int n,d;
int a[MAXN1];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1);
		int low = 0, high = d, res = 0;
		if(n == 2) {
			
		}
		while(low <= high) {
			int mid = (low + high) >> 1;
			int minn = inf, maxx = -inf;
			int cnt = 0;
			bool bad = false;
			for(int i = 1; i <= n + 1;) {
				
				if(i == n + 1) {
					maxx = max(maxx, d - a[i - 1] - 1);
					break;
				}
				
				else if(i == 1) {
					int r = i;
					while(r <= n && a[r] - 1 < mid) {
						cnt++;
						if(cnt == 2) {
							bad = true;
							break;
						}
						++r;
					}
					
					minn = min(minn, a[r] - 1);
					maxx = max(maxx, (a[r] - 2)/2);
					
					i = r + 1;
					
				}
				else {
					int r = i;
					if(r <= n && a[r] - a[i - 1] < mid) {
						cnt++;
						if(cnt == 2) {
							bad = true;
							break;
						}
						++r;
					}
					minn = min(minn, a[r] - a[i - 1]);
					maxx = max(maxx, (a[r] - a[i - 1] - 1)/2);
					i = r + 1;
				}
			}
			db(mid);
			db(maxx);
			db(minn);
			cerr << "\n";
			bad |= ((minn < mid) || (cnt && maxx < mid));
			//db(bad);
			if(bad) {
				high = mid - 1;
				continue;
			}
			else {
				res = mid;
				low = mid + 1;
			}
			
		}
		
		cout << res << '\n';
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}