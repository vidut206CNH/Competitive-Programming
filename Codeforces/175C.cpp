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


signed main() {
	fast_cin();
	
	
	int n,t;
	cin >> n;
	vector<pii > a(n+1);
	for(int i=1;i<=n;++i) cin >> a[i].fi >> a[i].se;
	
	sort(a.begin() + 1, a.end(), [&] (pii A, pii B) {
		return A.se < B.se;
	});
	cin >> t;
	vector<int> p(t+1); 
	for(int i=1;i<=t;++i) {
		cin >> p[i];
	}
	int pos = 1, sum = 0, ans = 0,f = 1;
	for(int i=1;i <= t;++i) {
		while(pos <= n && sum < p[i]) {
			int diff = min(p[i] - sum, a[pos].fi);
			ans += f*(diff)*a[pos].se;
			sum += diff;
			a[pos].fi -= diff;
			if(a[pos].fi == 0) ++pos;
		}
		++f;
	}
	while(pos <= n) {
		ans += f*a[pos].fi*a[pos].se;
		pos++;
	}
	
	cout << ans;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}