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
const double eps = 1e-8;

int n;
double m;
int a[MAXN1];
int b[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=n;++i) cin >> b[i];
	
	vector<int> p;
	for(int i=1;i<n;++i) {
		p.push_back(a[i]);
		p.push_back(b[i+1]);
	}
	p.push_back(a[n]);
	p.push_back(b[1]);
	
	double l=eps, r = 1e9,ans = 1e9+5;
	
	while(r - l > eps) {
		double mid = (l+r)/2;
		
		double weight = mid + m;
		
		bool good = 1;
		for(auto x : p) {
			
			weight = weight - weight/(1.0*x);
			
			if(m - weight > eps) {
				good = 0;
				break;
			}
		}
		
		if(good) {
			if(ans - mid > eps) ans = mid;
			r = mid;
		}
		else l = mid;
		
/*		db(l);
		db(r);
		cerr << "\n";*/
	}
	if(ans == 1e9+5) cout << -1;
	else cout << fixed << setprecision(15) << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}