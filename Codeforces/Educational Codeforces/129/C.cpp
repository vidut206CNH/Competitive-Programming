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

int t,n;
int a[105];
int b[105];


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int j = 1; j <= n; ++j) cin >> b[j];
		
		
		vector<pii> res;
		bool ok = true;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				if(a[i] > a[j]) {
					res.push_back({i, j});
					swap(a[i], a[j]);
					swap(b[i], b[j]);
				}
				
				if(a[i] == a[j]) {
					if(b[i] > b[j]) {
						res.push_back({i,j});
						swap(a[i], a[j]);
						swap(b[i], b[j]);
					}
				}
			}
		}
		
		for(int i = 2; i <= n; ++i) ok &= (b[i] >= b[i - 1]);
		if(!ok) cout << "-1\n";
		else {
			cout << sz(res) << "\n";
			for(auto x : res) cout << x.fi << " " << x.se << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}