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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		vector<int> a(n + 1);
		vector<int> cost(m + 1);
		for(int i=1;i<=n;++i) {
			cin >> a[i];
		}
		
		for(int i=1;i<=m;++i) cin >> cost[i];
		sort(a.begin() + 1, a.begin() + n + 1);
		int res = 0;
		
		int low = max(0LL, n - m), high = n;
		while(low <= high) {
			int mid = (low + high) >> 1;
			
			if(cost[a[mid]] <= cost[n - mid]) {
				int sum = 0, d = 0;
				for(int i=1;i<=mid;++i) sum += cost[a[i]];
			
				for(int i = 1; i<= (n - mid);++i) {
					d += cost[i];
				}
				res = sum + d;
				low = mid + 1;
			} else high = mid - 1;
		}
		cerr << '\n';
		cout << res << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}