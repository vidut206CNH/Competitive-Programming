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


int n,k,l;
int a[MAXN1];
int d[2*MAXN1];
int b[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> k >> l;
	
	for(int i=1;i<=n;++i) cin >> a[i];
	
	sort(a+1,a+n+1,greater<int>());
	
	
	
	int le = 0,ri = n,ans = 0;
	
	while(le <= ri) {
		
		int mid = (le + ri)/2;
		memset(d, 0, sizeof d);
		
		int m = 0;
		
		
		for(int i=1;i<=mid;++i) {
			m += max(0LL, mid - a[i]);
		}
		
		if(m <= k*l && a[mid] + k >= mid) {
			ans = max(ans, mid);
			le = mid + 1;
		}
		else ri = mid - 1;
		//cerr << "\n";
	}
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}