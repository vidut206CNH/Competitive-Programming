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

signed main() {
	fast_cin();
	
	
	int t;
	cin >> t;
	while(t--) {
		int n,k,sum = 0;
		cin >> n >> k;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			sum += a[i];
		}
		
		if(n == 1) {
			cout << max(0LL, sum - k) << "\n";
			continue;
		}
		
		if(sum <= k) {	
			cout << 0 << "\n";
			continue;
		}
		
		sort(a+1,a+n+1, greater<int>());
		
		int l=1,r=1e15	;
		int ans = INF;
		
		while(l <= r) {
			int mid = (l+r) >> 1;
			
			int tmp = sum - mid;
			int id = 1;
			while(id < n && tmp > k) {
				tmp -= (a[id] - a[n] + mid);
				id++;
			}
			id--;
			
			if(tmp > k) {
				l = mid + 1;
				continue;
			}
			
			if(tmp <= k) ans = min(ans, id + mid);
			
			if(tmp - (id - 1) + (a[id]))
			
			
		}
		cout << ans << "\n";	
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}