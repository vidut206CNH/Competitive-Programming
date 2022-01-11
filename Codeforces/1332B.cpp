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

int a[1005];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> ok(1005, 0);
		for(int i=1;i<=n;++i) {
			cin >> a[i];
		}
		
		for(int i=2;i*i<=1000;++i) {
			if(!ok[i]) {
				ok[i] = i;
				for(int j=i*i;j <= 1000; j += i) {
					if(ok[j] == 0) ok[j] = i;
				}
			}
		}
		vector<int> color(1005,0), res(n+1);
		unordered_set<int> st;
		int d = 0;
		for(int i=1;i<=n;++i) {
			if(st.count(ok[a[i]]) == 0) {
				color[ok[a[i]]] = ++d;
			}
			res[i] = color[ok[a[i]]];
			st.insert(ok[a[i]]);
		}
		
		cout << d << "\n";
		for(int i=1;i<=n;++i) cout << res[i] << " ";
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}