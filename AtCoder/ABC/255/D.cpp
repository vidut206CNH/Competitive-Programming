/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int n,q;
long long a[MAXN1];
long long f[MAXN1];

int main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n + 1; ++i) {
		f[i] = f[i - 1] + a[i];
	}	
	
	while(q--) {
		int x;
		cin >> x;
		int id = upper_bound(a + 1, a + n + 1, x) - a;
		long long res = 0;
		res += (1LL*(id - 1)*x - f[id - 1]);
		if(id <= n) {
			res += ((f[n] - f[id - 1]) - 1LL*(n - id + 1)*x);
		}
		
		cout << res << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}