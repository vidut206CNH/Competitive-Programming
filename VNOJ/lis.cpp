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
const int MAXN1 = 3e4+5;
const int MAXN2 = 1e6+5;

int n,x;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	memset(a,0x3f3f, sizeof(a[0])*(n+1));
	int ans = 0;
	for(int i=1;i<=n;++i) {
		cin >> x;
		int t = lower_bound(a+1,a+i+1,x) - a;
		a[t] = x;
		ans = max(t, ans);
	}
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}