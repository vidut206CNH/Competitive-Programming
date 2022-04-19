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
pii p[31];

signed main() {
	fast_cin();
	
	
	cin >> t;
	
	for(int i = 0; i <= 29; ++i) {
		p[i] = {(1LL << i), (1LL << i) + (1LL << (i + 1))};
	}
	while(t--) {
		int rem = 0;
		for(int i = 0; i <= 29; ++i) {
			cout << "? " << p[i].fi - rem << " " << p[i].se - rem << endl;
			int x;
			cin >> x;
			if(!(x&((1LL << (i + 1)) - 1))) {
				rem += (1LL << i);
			}
			//cout.flush(); 
		}
		
		cout << "! " << rem << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}