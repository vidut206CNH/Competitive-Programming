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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int a[MAXN1];
int b[MAXN1];

signed main() {
	fast_cin();
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			if(i > 1) b[i-1] = a[i] - a[i-1];
		}
		
		sort(b + 1, b + n);
		int res = 0;
		for(int i=1;i<n;++i) {
			res = gcd(res, b[i] - b[1]);
		}
		if(res == 0) cout << "0\n";
		else {
			int c = (b[1] + res*res)%res;
			bool ok = (a[1] < res);
			for(int i=2;i<=n;++i) {
				ok &= (a[i] == (a[i-1] + c)%res);
			}	
			if(ok) cout << res << " " << c << "\n";
			else cout << "-1\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}