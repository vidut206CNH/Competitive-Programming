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

int n;
char a[MAXN1];
int f[MAXN1];
int best[MAXN1];

int func(char c) {
	for(int i=1;i<=n;++i) {
		f[i] = (c == a[i] ? 1 : -1);
		f[i] += f[i-1];
		best[i] = min(best[i-1], f[i]);
	}
	
	int ans = -1;
	
	for(int i=1;i<=n;++i) {
		int l = 0, r = i-1,res = -1;
		while(l <= r) {
			
			int mid = (l + r) >> 1;
			if(f[i] - best[mid] > 0) {
				res = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		
		if(res != -1) ans = max(ans, i - res);
	}
	
	return ans;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	
	int res = func('a');
	res = max(res, func('b'));
	res = max(res, func('c'));
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}