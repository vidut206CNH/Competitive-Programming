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



signed main() {
	fast_cin();

	int t;
	cin >> t;
	while(t--) {	
		int a,b,c;
		cin >> a >> b >> c;
		if(b > c) swap(b,c);
		if(a > b) swap(a,b);
		if(b > c) swap(b,c);
		bool ok = 0;
		if(a == b && c%2==0 || b == c && a%2==0) ok = 1;
		if(c == a + b) ok = 1;
		cout << (ok ? "YES\n" : "NO\n"); 
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}