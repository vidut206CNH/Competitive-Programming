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


int bi(int &n, int p) {
	int l=1,r=n;
	int ans = 1;
	while(l <= r) {
		int mid = (l+r)/2;
		int prod = 1;
		bool bad = 0;
		for(int i=1;i<=p;++i) {
			if(n/mid < prod) {
				bad = 1;
				break;
			}
			prod *= mid;
		}
		if(bad) {
			r = mid -1;
		}
		else {
			l = mid + 1;
			ans = max(ans, mid);
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	cout << bi(n, 2) + bi(n, 3) - bi(n, 6) << "\n";
}

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}