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
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int n;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1);
		vector<int> p;
		
		for(int i = 1; i <= n;) {
			int j = i;
			while(j <= n && a[i] == a[j]) {
				++j;
			}
			p.push_back(j - i);
			i = j;
		}
		
		sort(p.begin(), p.end());
		for(int i = 1; i <= sz(p); ++i) cout << sz(p) << " ";
		for(int i = 1; i <= n - sz(p); ++i) {
			cout << i + sz(p) << " ";
		}
		
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}