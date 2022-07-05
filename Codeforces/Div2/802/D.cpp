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
long long a[MAXN1], f[MAXN1];
long long g[MAXN1], maxx[MAXN1];

int main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	for(int i = 1; i <= n; ++i) {
		f[i] = f[i - 1] + a[i];
		g[i] = f[i]/i + (f[i]%i != 0);
		maxx[i] = max(maxx[i - 1], g[i]);
	}
	
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		int low = 1, high = n;
		int res = -1;
		while(low <= high) {
			int mid = (low + high) >> 1;
			
			bool good = true;
			good &= (x >= maxx[mid]);
			good &= (x >= f[n]/mid + (f[n]%mid != 0));
			
			if(!good) {
				low = mid + 1;
			}
			
			else {
				res = mid;
				high = mid - 1;
			}
		}
		
		cout << res << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}