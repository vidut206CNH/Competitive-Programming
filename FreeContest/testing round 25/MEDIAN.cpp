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

int n;
int a[MAXN1];
int b[MAXN1];
int f[MAXN1], bit[MAXN1];
pii g[MAXN1];


int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= (pos&-pos)) res += bit[pos];
	return res;
}

void update(int pos) {
	for(;pos <= n + 1;pos += (pos&-pos)) bit[pos] += 1;
}


signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=n;++i) b[i] = a[i];
	sort(b + 1, b + n + 1);
	
	int l = 1, r = n;
	int ans = 0;
	int sz = ((n + 1)*n/2 + 1)/2;
	while(l <= r) {
		
		int mid = (l + r) >> 1;
		int val = b[mid];
		memset(bit, 0, sizeof bit);
		for(int i=2;i<=n + 1;++i) f[i] = f[i-1] + (a[i - 1] >= val);
		g[1].fi = -1;
		g[1].se = 1;
		for(int i=2;i<=n + 1;++i) {
			g[i].fi = 2*f[i] - i;
			g[i].se = i;

		}
		sort(g + 1, g + n + 2);
		int cnt = 0;
		for(int i=1;i<=n + 1;++i) {
			int pos = g[i].se;
			cnt += get(pos);
			update(pos);
		}
/*		db(cnt);
		db(val);
		cerr << "\n";*/
		
		if(cnt >= sz) {
			ans = val;
			l = mid + 1;
		} else r = mid - 1;
		
	}
	
	
	cout << ans;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}