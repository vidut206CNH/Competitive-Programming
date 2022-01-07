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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


struct flo{
	int id;
	int h;
	int val;
	bool operator() (const flo &A, const flo &B) {
		return A.h < B.h;
	}
};

int n;
int dp[MAXN1];
flo a[MAXN1];

void update(int pos) {
	int g = dp[pos];
	for(;pos <= n; pos += pos&-pos) dp[pos] = max(dp[pos], g);
}

int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= pos&-pos) res = max(res, dp[pos]);
	return res;
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i <= n;++i) {
		cin >> a[i].h;
		a[i].id = i;
	}
	for(int i=1;i <= n; ++i) cin >> a[i].val;
	
	sort(a + 1,a + n + 1, flo());
	int ans = 0;
	for(int i=1;i <= n;++i) {
		dp[a[i].id] = get(a[i].id) + a[i].val;
		update(a[i].id);
		ans = max(ans, dp[a[i].id]);
		//db(dp[a[i].id]);
		//cerr << "\n";
	}
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}