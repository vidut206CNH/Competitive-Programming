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

int t,n,d;

int check(int x) {
	for(int i = 2;i*i <= x; ++i) {
		if(x%i) continue;
		return true;
	}
	
	
	return false;
}


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n >> d;
		int cnt = 0;
		while(n%d == 0) {
			n /= d;
			cnt++;
		}
		if(cnt == 1) {
			cout << "NO\n";
			continue;
		}
		
		if(n == 1 && cnt == 2) {
			cout << "NO\n";
			continue;
		}
		else if(cnt == 2 && check(n)) {
			cout << "YES\n";
			continue;
		}
		
		n *= d;
		
		bool good = false;
		for(int i = 2; i *i <= n; ++i) {
			if(n%i) continue;
			good |= (i%d && (n/i)%d);
		}
		
		cout << (good ? "YES\n" : "NO\n");
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}