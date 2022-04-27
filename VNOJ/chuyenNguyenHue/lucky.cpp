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
const int MAXN1 = 62;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int res[MAXN1 + 5];
int f[MAXN1 + 5];

signed main() {
	fast_cin();
	
	cin >> n;
	
	for(int i = 1; i <= MAXN1; ++i) {
		f[i] = f[i - 1] + (1LL << i);
	}
	
	int pos = lower_bound(f + 1, f + MAXN1 + 1, n) - f;
	
	n -= f[pos - 1];
	
	for(int i = 1; i <= pos; ++i) {
		
		if(n <= (1LL << (pos - i))) {
			res[i] = 1;
		}
		
		else {
			n -= (1LL << (pos - i));
			res[i] = 2;
		}
		
	}
	//db(pos);
	for(int i = 1; i <= pos; ++i) cout << res[i];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}