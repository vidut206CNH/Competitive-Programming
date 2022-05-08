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

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res*a;
		a = a*a;
		b /= 2;
	}
	
	return res;
}

signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		string a,b;
		cin >> a >> b;
		bool all_a = true, has_a = false;
		for(auto x : b) {
			has_a |= (x == 'a');
			all_a &= (x == 'a');
		}
		
		if(all_a && sz(b) == 1) {
			cout << 1 << "\n";
		}
		
		else if(has_a || all_a) {
			cout << -1 << "\n";
		}
		
		else cout << power(2, sz(a)) << "\n";
		
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}