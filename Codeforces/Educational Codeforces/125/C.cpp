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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
char a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cin.ignore();
		for(int i = 1; i <= n; ++i) cin >> a[i];
		int cnt = 0, d = 0;
		
		int id = 1;
		while(id < n) {
			if(a[id] == '(') {
				d += 2;
				id += 2;
				cnt++;
			}
			else {
				if(id < n && a[id] == ')' && a[id + 1] == ')') {
					d += 2;
					id += 2;
					cnt++;
				}
				else {
					int l = id;
					++id;
					while(id <= n && a[id] == '(') ++id;
					if(id <= n) {
						cnt++;
						d += (id - l + 1);
					}
					++id;
				}
			}
		}
		
		cout << cnt << " " << n - d << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}