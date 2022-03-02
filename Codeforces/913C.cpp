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
const int inf = 1e18 + 17;

int n,w;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> w;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(i > 0) a[i] = min(a[i - 1]*2, a[i]);
	}
	int res = 0;
	
	for(int i = n - 1; i >= 0; --i) {
		if(w <= 0) break;
		int d = w/(1 << i);
		w = w & ((1 << i ) - 1);
		if(i > 0 && w && a[i] == 2*a[i - 1]) {
			res += d*a[i];
		} else {
			res += (d + 1)*a[i];
			w = 0;
		}
	}
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}