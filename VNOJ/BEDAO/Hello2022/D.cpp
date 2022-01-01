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

int f[105];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	f[0] = 1;
	for(int i=1;i<=61;++i) f[i] = f[i-1]*2;
	while(t--) {
		int n,id = 0;
		cin >> n;
		vector<int> p,res;
		// if(n==1) {
			// cout << 1 << "\n2\n";
			// continue;
		// }
		if(n%2) {
			res.push_back(1);
			id++;
		}
		
		for(int i=1;i<=61;++i) {
			if(n >> i &1) p.push_back(i);
		}
		for(auto x : p) {
			res.push_back(f[x - id]);
			id++;
		}
		cout << sz(res) << "\n";
		for(auto x : res) cout << x << " ";
		cout << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}