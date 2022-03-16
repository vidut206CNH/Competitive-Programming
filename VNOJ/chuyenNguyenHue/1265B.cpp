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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int a[MAXN1];
int L[MAXN1], R[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		deque<int> d;
		
		for(int i = 1; i <= n; ++i) {
			while(!d.empty() && a[d.back()] < a[i]) d.pop_back();
			if(d.empty()) {
				L[i] = i;
			} else {
				L[i] = i - d.back();
			}
			d.push_back(i);
		}
		
		while(!d.empty()) d.pop_back();
		for(int i = n; i >= 1; --i) {
			while(!d.empty() && a[d.back()] < a[i]) d.pop_back();
			if(d.empty()) {
				R[i] = n - i + 1;
			}
			else R[i] = d.back() - i;
			d.push_back(i);
		}
		
		vector<int> res(n + 1);
		for(int i = 1; i <= n; ++i) {
			res[a[i]] = (L[i] + R[i] - 1 == a[i]);
/*			db(a[i]);
			db(res[a[i]]);
			cerr << "\n";*/
		}
		
		for(int i = 1; i <= n; ++i) cout << res[i];
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}