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
const int inf = 1e18;

int f[3][MAXN1];



signed main() {
	fast_cin();
	
	
	int n;
	vector<int> p(3);
	cin >> n;
	for(int i = 0; i < 3; ++i) cin >> p[i];
	
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		
		for(int k = 0; k < 3; ++k) {
			f[k][i] = f[k][i - 1] + (k == x);
		}
		
	}
	int res = n + 1;
	
	for(int i = 1; i <= n; ++i) {
		int low = i, high = n;
		while(low <= high) {
			int mid = (low + high) >> 1;
			bool good = true;
			
			for(int k = 0; k < 3; ++k) {
				good &= (f[k][mid] - f[k][i - 1] >= p[k]);
			}
			
			if(good) {
				res = min(res, mid + 1 - i);
				high = mid - 1;
			}
			else low = mid + 1;
		}
	}
	
	cout << (res == n + 1 ? -1 : res);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}