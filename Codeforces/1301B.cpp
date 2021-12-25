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
const int MAXN1 = 4e5+5;
const int MAXN2 = 1e6+5;

int a[MAXN1];
int b[MAXN1];
int f[MAXN1];
int n;

void solve() {
	cin >> n;
	
	
	unordered_set<int> s;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		s.insert(a[i]);
	}
	
	
	if(s.size() <= 2) {
		if(s.size() == 1) {
			cout << "0 0\n";
		} else {
			auto it = s.begin();
			if((*it) == -1) ++it;
			cout << 0 << " " << (*it) << "\n";
		}
		return;
	}
	
	int l = 0, r = 1e9,m = 2e9,k;
	while(l <= r) {
		int mid = (l+r) >> 1;
		
		
		for(int i=1;i <= n;++i) {
			if(a[i] == -1) {
				b[i] = mid;
			}
			else b[i] = a[i];
		}
		for(int i=2;i<=n;++i) {
			if(a[i-1] == -1) {
				f[i-1] = b[i-1] - b[i]; 
			}
			else f[i-1] = b[i] - b[i-1];
		}
		
		sort(f + 1, f + n);
		
		if(m > abs(f[1]) && m > abs(f[n-1])) {
			
			m = max(abs(f[1]), abs(f[n-1]));
			k = mid;
		}
		
		if(abs(f[n-1]) >= abs(f[1])) {
			r = mid - 1;
		}
		else l = mid + 1;
		
		//cout << k << " " << m << "\n";
	}
	
	cout << m << " " << k << "\n";
}

int t;


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		solve();
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}