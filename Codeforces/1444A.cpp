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

int power(int a,int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res*a;
		a *= a;
		b /= 2;
	}
	return res;
}


signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		int p,q;
		cin >> p >> q;
		if(p%q) {
			cout << p << "\n";
		} else{
			vector<pii > d;
			for(int i=2;i*i<=q;++i) {
				if(q%i == 0) {
					int cnt = 0;
					while(q%i == 0) {
						cnt++;
						q/=i;
					}
					d.push_back({i,cnt});
				}
			}
			
			int ans = 0;
			
			if(q > 1) d.push_back({q, 1});
			
			for(auto x : d) {
				int tmp = p;
				int cnt = 0;
				while(tmp%x.fi == 0) {
					cnt++;
					tmp /= x.fi;
				}
				ans = max(ans, tmp*power(x.fi, min(x.se - 1, cnt)));
			}
			
			
			cout << ans << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}