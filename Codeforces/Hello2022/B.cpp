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


struct data{
	int l,r,cost;
};

int t;
data a[MAXN1];
data dp[MAXN1];


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;++i) {
			cin >> a[i].l >> a[i].r >> a[i].cost;
		}
		data bestl = a[1];
		data bestr = a[1];
		data abest = a[1];
		
		cout << a[1].cost << "\n";
		for(int i=2;i<=n;++i) {
			if(a[i].r == bestr.r && bestr.cost > a[i].cost) {
				bestr = a[i];
			}
			if(a[i].l == bestl.l && bestl.cost > a[i].cost) {
				bestl = a[i];
			}
			if(a[i].l < bestl.l) bestl = a[i];
			if(a[i].r > bestr.r) bestr = a[i];
			if(abest.l > bestl.l || abest.r < bestr.r || abest.cost > bestl.cost + bestr.cost) {
				abest = {bestl.l,bestr.r, bestl.cost + bestr.cost};
			}
			
			if(abest.l == a[i].l && abest.r == a[i].r && a[i].cost < abest.cost) {
				abest = a[i];
			}
			
			cout << abest.cost << "\n";
		}
		
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}