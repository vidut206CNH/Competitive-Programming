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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const double eps = 1e-10;

int a[MAXN1];


double minimize(double A, double B) {
	if(A - B < eps) return A;
	return B;
}

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		int n,des;
		cin >> n >> des;
		a[0] = 0;
		a[n+1] = des;
		for(int i=1;i<=n;++i) cin >> a[i];
		
		double l=0,r = (double)des;
		
		while(r - l > eps) {
			
			double mid = (r+l)/2;
			double d = 1,time = 0, pos1 = 0, pos2 = (double)des;
			
			for(int i=1;i<=n + 1;++i) {
				double pos = minimize((mid - time)*d, (double)a[i] - pos1);
				pos1 += pos;
				time += pos/d;
				d++;
			}
			
			d = 1;
			time = 0;
			
			for(int i=n;i >= 0; --i) {
				double pos = minimize((mid - time)*d, pos2 - (double)a[i]);
				pos2 -= pos;
				time += pos/d;
				d++;
			}
			
			if(pos2 - pos1 > eps) {
				l = mid;
			}
			
			else if(pos1 - pos2 > eps) {
				r = mid;
			}
			else break;
		}
		
		cout << fixed << setprecision(15) << (l+r)/2 << "\n";
		
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}