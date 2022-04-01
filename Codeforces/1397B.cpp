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
const int inf = 1e14 + 7;

int n;
int a[MAXN1];
int f[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	
	int res = abs(sum - n);
	
	for(int c = 2; c <= (int)1e5; ++c) {
		
		bool bad = false;
		
		f[0] = 1;
		for(int k = 1; k < n; ++k) {
			
			if(f[k - 1] > inf/c) {
				bad = true;
				break;
			}
			
			f[k] = f[k - 1]*c;
		}
		
		if(!bad) {
			int d = 0;
			for(int i = 0; i < n; ++i) {
				d += abs(f[i] - a[i]);
			}
			
			res = min(res, d);
		}
		
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}