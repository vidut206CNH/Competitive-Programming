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
		int n;
		cin >> n;
		vector<int> a;
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		vector<int> res(n);
		for(int pos = n - 1;pos >= 0; --pos) {
			vector<int> d = a;
			int maxx = -1, id = 0;
			for(int i = 0; i < sz(d); ++i) {
				if(maxx < d[i]) {
					maxx = d[i];
					id = i;
				}
			}
			a.clear();
			res[pos] = (id + 1)%sz(d);
			for(int i = id + 1; i < sz(d); ++i) a.push_back(d[i]);
			for(int i = 0; i < id; ++i) a.push_back(d[i]);
/*			for(auto x : a) db(x);
			cerr << "\n";*/
		}
		
		for(auto x : res) cout << x << " ";
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}