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
const int MAXN1 = 4e7+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
vector<int> p;
bool isp[MAXN1];

signed main() {
	fast_cin();
	
	memset(isp, true, sizeof isp);
	
	for(int i = 2; i < MAXN1; ++i) {
		if(isp[i] == false) continue;
		
		p.push_back(i);
		for(int j = i*i; j < MAXN1; j += i) isp[j] = false;
	}
	
		
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int res = 0;
		
		for(auto x : p) {
			int d = n;
			if(x*x*x > n) break;
			d /= (x*x*x);
			
			for(auto y : p) {
				if(y == x) continue;
				if(y*y > d) break;
				int m = d/(y*y);
				res += (upper_bound(p.begin(), p.end(), m) - p.begin());
				if(m >= y) res--;
				if(m >= x) res--;
/*				db(x);
				db(y);
				db(m);
				db(res);
				cerr << "\n";*/
			}
		}
		
		cout << res << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}