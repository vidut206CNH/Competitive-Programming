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

int t;

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		vector<pii > a(n);
		vector<bool> ok(n);
		for(int i=0;i<n;++i) {
			cin >> a[i].fi;
			a[i].se = i;
		}
		
		sort(a.begin(), a.end());
		int minn = inf, id;
		int len = n - (n - k)/2;
		for(int i = len-1;i<n;++i) {
			if(a[i].fi - a[i - len + 1].fi < minn) {
				minn = a[i].fi - a[i - len +1].fi;
				id = i;
			}
		}
		int x,y;
		x = a[id - len + 1].fi;
		y = a[id].fi;
		
		for(int i = id;i > id - len;--i) {
			int pos = a[i].se;
			ok[pos] = true;
		}
		cout << x << " " << y << "\n";
		
		int l = 0,r = 0,cnt = 0;
		while(r < n) {
			cnt += (ok[r]);
			
			if(k == 1) {
				cout << l + 1 << " " << n << '\n';
				break;
			}
			if(r - l + 1 < 2*cnt) {
				cout << l + 1 << " " << r + 1 << "\n";
				cnt = 0;
				l = r + 1;
				--k;
			}
			++r;
		}
		
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}