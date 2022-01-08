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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,x;
int bit[2][MAXN1];
pii a[MAXN1];
int s[MAXN1],g[MAXN1];

int get(int pos, bool dir) {
	int res = 0;
	if(!dir) for(;pos > 0;pos -= pos&-pos) res += bit[dir][pos];
	else for(;pos <= n;pos += pos&-pos) res += bit[dir][pos];
	return res;
}

void update(int pos, bool dir) {
	if(!dir) for(;pos <= n;pos += pos&-pos) bit[dir][pos]++;
	else for(;pos > 0;pos -= pos&-pos) bit[dir][pos]++;
}

int find(int pos, bool dir) {
	int l=1,r = pos,ans = 0,d = get(pos, dir);
	if(dir) {
		l = pos;
		r = n;
	}
	while(l <= r) {
		int mid = (l+r) >> 1;
		int m = get(mid - 1, dir);
		if(dir) m = get(mid + 1, dir);
		if((!dir && d - m < abs(pos - mid) + 1) || (dir && d - m == abs(pos - mid) + 1)) {
			if(dir) ans = max(ans, abs(pos - mid));
			l = mid + 1;
		}
		else {
			if(!dir) ans = max(abs(pos - mid), ans);
			r = mid - 1;
		}
	}
	return ans;
}

signed main() {
	fast_cin();
	cin >> n >> x;
	for(int i=1;i <= n;++i) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;++i) {
		update(a[i].se, 0);
		s[a[i].se] = find(a[i].se,0);
		//db(s[i]);
	}
	//memset(bit, 0, sizeof bit);
	for(int i=n;i>=1;--i) {
		update(a[i].se, 1);
		g[a[i].se] = find(a[i].se, 1);
	}
	int res = 0;
	
	for(int i=1;i<=n;++i) {
		if(a[i].fi >= x) {
			res++;
			res += min(s[i], g[i]);
			res += min(s[i] - 1, g[i]);
		}
		
		db(s[i]);
		db(g[i]);
		cerr << "\n";
	}
	
	cout << res << "\n";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}