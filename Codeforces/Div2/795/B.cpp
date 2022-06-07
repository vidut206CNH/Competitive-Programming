/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int t;
int a[MAXN1];
int res[MAXN1];

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		
		bool bad = false;
		int id = 1;
		while(id <= n) {
			int j = id + 1;
			while(j <= n && a[j] == a[id]) {
				++j;
			}
			--j;
			
			if(j == id) {
				bad = true;
				break;
			}
			
			res[id] = j;
			for(int k = id + 1; k <= j; ++k) {
				res[k] = k - 1;
			}
			
			id = j + 1;
		}
		
		
		if(bad) cout << "-1\n";
		else {
			for(int i = 1; i <= n; ++i) cout << res[i] << " \n"[i == n];
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}