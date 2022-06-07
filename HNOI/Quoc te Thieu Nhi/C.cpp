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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const double eps = 1e-9;

long long n,k,h;
int a[MAXN1];
double b[MAXN1];
double f[MAXN1];

int main() {
	fast_cin();
	
	cin >> n >> k >> h;	
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	double low = 0, high = 1e5, res;
	
	while(high - low > eps) {
		double mid = (low + high)/2;
		for(int i = 1; i <= n; ++i) {
			f[i] = f[i - 1] + 1.0*a[i] - mid;
		}
		
		bool good = false;
		double minn = 0;
		for(int i = k; i <= n; ++i) {
			minn = min(minn, f[i - k]);
			good |= (f[i] - minn >= 0.0);
		}
		
		
		if(good) {
			low = mid;
			res = mid;
		}
		
		else high = mid;
	}
	if(h == 0) cout << (long long)res;
	else cout << fixed << setprecision(3) << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}