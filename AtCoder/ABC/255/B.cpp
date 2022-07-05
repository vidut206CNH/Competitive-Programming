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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const double eps = 1e-9;
int n,k;

bool ok[MAXN1];
int p[MAXN1];
pii a[MAXN1];

double dist(const pii&A, const pii&B) {
	return sqrt(1LL*(A.fi - B.fi)*(A.fi - B.fi) + 1LL*(A.se - B.se)*(A.se - B.se));
}

int main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= k; ++i) {
		cin >> p[i];
	}	
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;
	}
	double low = 0, high = 1e6, res;
	
	while(high - low > eps) {
		double mid = (low + high)/2;
		
		memset(ok, false, sizeof ok);
		
		for(int i = 1; i <= k; ++i) {
			int id = p[i];
			for(int j = 1; j <= n; ++j) {
				if(dist(a[id], a[j]) <= mid) ok[j] = true;
			}
		}
		bool good = true;
		
		for(int i = 1; i <= n; ++i) good &= (ok[i]);
		
		if(good) {
			res = mid;
			high = mid;
		}
		else low = mid;
	}
	
	cout << fixed << setprecision(9) << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}