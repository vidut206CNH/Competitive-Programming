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
const int MAXN1 = 5e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

bool p[MAXN1];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	for(int i=2;i*i <= 50000;i++) {
		if(!p[i]) for(int j=i*i;j <= 50000;j += i) p[j] = 1;
	}
	vector<int> a;
	for(int i=2;i <= 50000;++i) {
		if(!p[i]) a.push_back(i);
	}
	while(t--) {
		int d;
		cin >> d;
		int ans = inf;
		int l = lower_bound(a.begin(), a.end(), 1 + d) - a.begin();
		int r = lower_bound(a.begin() + l + 1, a.end(), a[l] + d) - a.begin();
		if(r != sz(a)) ans = a[l]*a[r];
		for(int i=1;i*i - i <= 10000;++i) {
			if(i >= 1 + d && i*i - i >= d) {
				ans = min(ans, i*i*i);
				break;
			}
		}
		
		cout << ans << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}