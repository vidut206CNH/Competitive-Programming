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
const int MAXN1 = 3e5+5;
const int inf = 1e18;

int n,m;

int a[35];
int p[MAXN1];
int s[2005];
int f[35];


void sub3() {
	
	for(int i=1;i<=n;++i) {
		f[i] = -inf; 
	}
	for(int state=1; state < (1 << n); ++state) {
		int minn = inf,sum = 0;
		for(int i=0;i<n;++i) {
			if(state >> i & 1) {
				sum += a[i+1];
				minn = min(minn, sum); 
			}
		}
		int num = __builtin_popcount(state);
		f[num] = max(f[num], minn);
	}
	
	for(int i=1;i<=m;++i) {
		int res = 0;
		for(int j=1;j<=n;++j) {
			if(p[i] >= -f[j]) res = j;
/*			db(f[j]);
			db(j);
			cerr << "\n";*/
		}
		cout << res << " ";
	}
}

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}	

	for(int i=1;i<=m;++i) {
		cin >> p[i];
	}
	bool inc=1,dec=1;
	for(int i=1;i<n;++i) {
		inc &= (a[i] <= a[i+1]);
		dec &= (a[i] >= a[i+1]);
	}
	

	
	if(dec) {
		for(int i=1;i<=n;++i) s[i] = s[i-1] + a[i];
		for(int i=1;i<=m;++i) {
			int l=1,r=n,pos;
			while(l <= r) {
				int mid = (l+r) >> 1;
				if(s[mid] < -p[i]) r = mid - 1;
				else {
					pos = mid;
					l = mid + 1;
				}
			}
			cout << pos << " ";
		}
		exit(0);
	}
	if(inc) {
		int lim = lower_bound(a + 1 ,a + n + 1, 0LL) - a;
		--lim;
		for(int i=lim;i>0;--i) {
			s[i] = s[i+1] + a[i];
		}
		db(lim);
		sort(s+1,s+lim+1);
		for(int i=1;i<=m;++i) {
			int pos = lower_bound(s+1,s+lim+1, -p[i]) - s;
			cout << n + 1 - pos << " ";
		}
		exit(0);
	}
	
	sub3();
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}