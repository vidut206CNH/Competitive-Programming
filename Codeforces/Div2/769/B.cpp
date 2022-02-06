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

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> res;
		int m = 0, p = 1;
		while(p < n) {
			++m;
			p <<= 1;
		}
		--m;
		for(int i=n - 1; i>= (1 << m); --i) {
			res.push_back(i);
		}
		res.push_back(0);
		
		for(int i=m;i >= 1; --i) {
			vector<int> tmp;
			for(int val = (1 << i) - 1; val >= (1 << (i - 1)); --val) {
				tmp.push_back(val);
			}
			if((m - i)%2 == 0) reverse(tmp.begin(), tmp.end());
			for(auto x : tmp) res.push_back(x);
			
		}
		
		reverse(res.begin(), res.end());
		
		for(auto x : res) cout << x << " ";
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}