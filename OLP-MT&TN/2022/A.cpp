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
const int MAXN1 = 5e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,R,k;
int a[MAXN1];
int use[MAXN1];
int b[MAXN1];
int d[MAXN1];
int f[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> R >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	for(int i = 1; i <= n; ++i) {
		int l = max(1LL, i - R);
		int r = min(n + 1, i + R + 1);
		d[l] += a[i];
		d[r] -= a[i];
	}
	
	for(int i = 1; i <= n; ++i) {
		d[i] += d[i - 1];
/*		db(d[i]);
		cerr << "\n";*/
	}
	
	int res = 0;
	int low = 1, high = *max_element(a + 1, a + n + 1) + k;
	
	while(low <= high) {
		int mid = (low + high) >> 1;
		for(int i = 1; i <= n; ++i) f[i] = d[i];
		
		memset(use, 0, sizeof use);
		
		bool can = true;
		int sum = 0;
		
		for(int i = n; i >= 1; --i) {
			if(f[i] < mid) {
				for(int pos = max(1LL, i - R); pos <= min(n, i + R); ++pos) {
					if(use[pos] + a[pos] < b[pos]) {
						int g = min(mid - f[i], b[pos] - a[pos] - use[pos]);
						sum += g;
						use[pos] += g;
						for(int j = max(1LL, i - R); j <= min(n, i + R); ++j) {
							f[j] += g;
						}
						if(f[i] == mid) break;
					}
				}
			}
		}
		
		for(int i = 1; i <= n; ++i) {
			if(f[i] < mid) {
				can = false;
				break;
			}
		}
		
		if(sum > k) can =false;
		
		if(can) {
			res = mid;
			low = mid + 1;
			db(sum);
		} else high = mid - 1;
	}
	
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}