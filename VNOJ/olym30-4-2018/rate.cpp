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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;
const double eps = 1e-9;

int n,k;
int a[MAXN1];
double b[MAXN1];


signed main() {
	fast_cin();
	
	freopen("rate.inp", "r", stdin);
	freopen("rate.out", "w", stdout);
	
	
	cin >> n >> k;
	
	
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	double low = 0, high = 1e6, res = 0;
	
	while(high - low > eps) {
		double mid = (low + high)/2;
		
		for(int i = 1; i <= n; ++i) {
			b[i] = a[i] - mid;
			b[i] += b[i-1];
		}
		
		double minn = 0;
		bool can = false;
		for(int i=k; i <= n; ++i) {
			
			minn = min(minn, b[i - k]);
			
			double sum = b[i] - minn;
			
			can |= (sum > 0.0);
		}
		
		if(can) {
			res = mid;
			low = mid;
		} else high = mid;
	}
	
	
	cout << fixed <<  setprecision(6) << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}