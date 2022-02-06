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
const int inf = 2e9  + 7;

int n,k;
int a[MAXN1];
int b[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=n;++i) cin >> b[i];
	int lo = 1, hi = 2e9,res = 0;
	while(lo <= hi) {
		int mid = (lo + hi) >> 1;
		int need = 0;
		for(int i=1;i<=n;++i) {
			if(inf/a[i] < mid) need = inf;
			need += max(0LL, a[i]*mid - b[i]);
		}
		
		if(need <= k) {
			res = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}