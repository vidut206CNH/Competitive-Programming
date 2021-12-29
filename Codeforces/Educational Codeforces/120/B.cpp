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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int a[MAXN1];
int ans[MAXN1];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n;
		for(int i=1;i<=n;++i) cin >> a[i];
		cin >> s;
		s = '0' + s;
		
		vector<pii > p,d;
		for(int i=1;i<=n;++i) {
			if(s[i] == '1') p.push_back({a[i], i});
			else d.push_back({a[i], i});
		}
		sort(p.begin(),p.end(), greater<pii >());
		sort(d.begin(), d.end(), greater<pii >());
		int val = n;
		for(auto x : p) {
			ans[x.se] = val;
			--val;
		}
		for(auto x : d) {
			ans[x.se] = val;
			--val;
		}
		for(int i=1;i <= n;++i) cout << ans[i] << " ";
		cout << "\n";	
		
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}