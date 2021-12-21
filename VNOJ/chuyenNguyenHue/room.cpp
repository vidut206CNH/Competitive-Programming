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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;

int n;
pii a[MAXN1];
int dp[MAXN1];

bool comp(const pii& A, const pii& B) {
	if(A.se != B.se) return A.se < B.se;
	return A.fi < B.fi;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a+1,a+n+1, comp);
	
	dp[1] = a[1].se - a[1].fi; 
	
	for(int i=2;i<=n;++i) {
		
		int l=1,r=i-1,mid,mx = 0;
		
		while(l <= r) {
			
			mid = (l+r)/2;
			if(a[mid].se <= a[i].fi) {
				l = mid + 1;
				mx = max(mx,mid);
			}
			else r = mid - 1;
		}
		
		dp[i] = max(dp[i-1], dp[mx] + a[i].se - a[i].fi);
		//cout << dp[i] << "\n";
	}
	
	cout << dp[n];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}