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
const int MAXN1 = 15e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int a[MAXN1];
int f[MAXN1];
int d[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		a[i] -= k;
		f[i] = a[i] + f[i-1];
		d[i] = min(f[i], d[i-1]);
	}
	int ans = 0;
	for(int i=1;i<=n;++i) {
		int low = 0, high = i-1, res = -1;
		
		while(low <= high) {
			int mid = (low + high) >> 1;
			if(f[i] - d[mid] >= 0) {
				res = mid;
				high = mid - 1;
			} else low = mid + 1;
		}
		
		if(res != -1) ans = max(ans, i - res);
	}
	
	cout << ans;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}