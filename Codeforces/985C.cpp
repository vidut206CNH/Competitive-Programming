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

int n,k,l;
int a[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> n >> k >> l;
	for(int i=1;i<= n*k; ++i) cin >> a[i];
	
	sort(a + 1, a + n*k + 1);
	
	int pos = 1;
	int cnt = 1;
	int res = a[pos];
	while(cnt < n) {
		++cnt;
		int lim = n*k - (n - cnt + 1)*k + 1;
		int d = lower_bound(a + pos + 1, a + lim + 1, a[pos] + l) - a;
		if(d == lim + 1) --d;
		pos = d;
		db(res);
		cerr << "\n";
		res += a[pos];
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}